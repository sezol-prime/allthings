/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:35:19 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 21:40:10 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_heredoc(t_ms *ms, t_redir *r, int is_child)
{
	int	fd;

	fd = ms_heredoc_build(ms, r->arg);
	ms_setup_signals_interactive();
	if (fd == -2)
	{
		if (is_child)
			exit(130);
		set_status(ms, 130);
		return (130);
	}
	if (fd < 0)
	{
		perror("heredoc");
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	open_redir_fd(t_redir *r)
{
	int	fd;

	fd = -1;
	if (r->type == T_LT)
		fd = open(r->arg, O_RDONLY);
	else if (r->type == T_GT)
		fd = open(r->arg,
				O_CREAT | O_WRONLY | O_TRUNC,
				0644);
	else if (r->type == T_DGT)
		fd = open(r->arg,
				O_CREAT | O_WRONLY | O_APPEND,
				0644);
	return (fd);
}

static int	apply_fd_to_stdio(t_redir *r, int fd)
{
	if (r->type == T_LT)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			close(fd);
			return (1);
		}
	}
	if (r->type == T_GT || r->type == T_DGT)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}

int	ms_redirs_apply(t_ms *ms, t_redir *r, int is_child)
{
	int	fd;

	while (r)
	{
		if (r->type == T_DLT)
		{
			if (handle_heredoc(ms, r, is_child) != 0)
				return (get_status(ms));
			r = r->next;
			continue ;
		}
		fd = open_redir_fd(r);
		if (fd < 0)
		{
			perror(r->arg);
			return (1);
		}
		if (apply_fd_to_stdio(r, fd) != 0)
			return (1);
		r = r->next;
	}
	return (0);
}
