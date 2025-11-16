/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:53 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 19:38:03 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	child_setup_fds(int in_fd, int out_fd)
{
	if (in_fd != -1)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (out_fd != -1)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}

void	child_exit_not_found(char **argv, char **envp)
{
	write(2, argv[0], ft_strlen(argv[0]));
	write(2, ": command not found\n", 20);
	free_split(envp);
	exit(127);
}

void	child_exec_error(char **argv, char **envp, char *path)
{
	if (errno == ENOENT)
	{
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": command not found\n", 20);
		free_split(envp);
		free(path);
		exit(127);
	}
	if (errno == EACCES)
	{
		perror(argv[0]);
		free_split(envp);
		free(path);
		exit(126);
	}
	perror(argv[0]);
	free_split(envp);
	free(path);
	exit(1);
}

void	child_try_builtin(t_ms *ms, t_cmd *c)
{
	int	i;

	i = 0;
	while (c->argv && c->argv[i] && c->argv[i][0] == '\0')
		i++;
	if (!c->argv || !c->argv[i])
		exit(0);
	c->argv += i;
	if (is_builtin(c->argv[0]) != 0)
		exit(run_builtin_child(ms, c));
}

void	child_empty_argv(char **envp)
{
	free_split(envp);
	exit(0);
}
