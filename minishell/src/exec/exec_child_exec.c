/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:17:20 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 20:25:24 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	child_try_exec(t_ms *ms, t_cmd *c, char **envp)
{
	char	*path;

	if (c->argv == NULL || c->argv[0] == NULL)
		child_empty_argv(envp);
	path = find_cmd(ms->env, c->argv[0]);
	if (path == NULL)
		child_exit_not_found(c->argv, envp);
	execve(path, c->argv, envp);
	child_exec_error(c->argv, envp, path);
}

static int	child_apply_redirs(t_ms *ms, t_cmd *c)
{
	if (ms_redirs_apply(ms, c->rd, 1) != 0)
		exit(1);
	return (0);
}

int	exec_child(t_ms *ms, t_cmd *c, int in_fd, int out_fd)
{
	char	**envp;

	ms_setup_signals_child();
	child_setup_fds(in_fd, out_fd);
	child_apply_redirs(ms, c);
	if (in_fd != -1)
		close(in_fd);
	if (out_fd != -1)
		close(out_fd);
	child_try_builtin(ms, c);
	envp = env_to_array(ms->env);
	child_try_exec(ms, c, envp);
	exit(1);
}
