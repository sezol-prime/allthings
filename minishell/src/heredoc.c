/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:39:39 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 17:51:36 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_signal;

static void	hd_loop(const char *delim, int wfd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		if (g_signal == SIGINT)
		{
			free(line);
			break ;
		}
		write(wfd, line, ft_strlen(line));
		write(wfd, "\n", 1);
		free(line);
	}
}

int	ms_heredoc_build(t_ms *ms, const char *delim)
{
	int	fds[2];

	if (pipe(fds) == -1)
		return (-1);
	ms->heredoc_sigint = 0;
	ms_setup_signals_heredoc();
	hd_loop(delim, fds[1]);
	close(fds[1]);
	if (ms->heredoc_sigint)
	{
		close(fds[0]);
		set_status(ms, 130);
		return (-2);
	}
	return (fds[0]);
}
