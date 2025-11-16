/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:18:31 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 21:24:01 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	wait_and_get_status(pid_t last_pid)
{
	pid_t	status;
	int		wstatus;
	int		ret;

	ret = 0;
	while (1)
	{
		status = wait(&wstatus);
		if (status <= 0)
			break ;
		if (status == last_pid)
		{
			if (WIFEXITED(wstatus))
				ret = WEXITSTATUS(wstatus);
			else if (WIFSIGNALED(wstatus))
				ret = 128 + WTERMSIG(wstatus);
		}
	}
	return (ret);
}

int	ms_exec(t_ms *ms, t_cmd *p)
{
	int		cmd_count;
	pid_t	last_pid;

	cmd_count = count_cmds(p);
	if (cmd_count == 1 && p->argv != NULL && p->argv[0] != NULL)
	{
		if (is_parent_only_builtin(p) != 0)
			return (single_parent_builtin(ms, p));
	}
	last_pid = spawn_pipeline(ms, p);
	if (last_pid == -1)
		return (1);
	return (wait_and_get_status(last_pid));
}
