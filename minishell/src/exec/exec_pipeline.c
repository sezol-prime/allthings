/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:18:10 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 21:13:52 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	pipe_prepare(t_cmd *c, int fds[2], int *in_fd)
{
	fds[0] = -1;
	fds[1] = -1;
	if (c->next && pipe(fds) == -1)
	{
		perror("pipe");
		if (*in_fd != -1)
			close(*in_fd);
		return (-1);
	}
	return (0);
}

static int	fork_fail_cleanup(int *in_fd, int fds[2])
{
	perror("fork");
	if (*in_fd != -1)
		close(*in_fd);
	if (fds[0] != -1)
		close(fds[0]);
	if (fds[1] != -1)
		close(fds[1]);
	return (-1);
}

static void	parent_path(int *in_fd, int f0, int f1, t_cmd *c)
{
	if (*in_fd != -1)
	{
		close(*in_fd);
		*in_fd = -1;
	}
	if (c->next)
	{
		close(f1);
		*in_fd = f0;
	}
}

static int	spawn_one_cmd(t_ms *ms, t_cmd *c, int *in_fd, pid_t *last_pid)
{
	int		fds[2];
	pid_t	pid;
	int		out_fd;

	if (pipe_prepare(c, fds, in_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (fork_fail_cleanup(in_fd, fds));
	if (pid == 0)
	{
		ms_setup_signals_child();
		if (c->next)
			close(fds[0]);
		out_fd = -1;
		if (c->next)
			out_fd = fds[1];
		exec_child(ms, c, *in_fd, out_fd);
	}
	parent_path(in_fd, fds[0], fds[1], c);
	*last_pid = pid;
	return (0);
}

pid_t	spawn_pipeline(t_ms *ms, t_cmd *p)
{
	int		in_fd;
	pid_t	last_pid;

	in_fd = -1;
	last_pid = -1;
	while (p)
	{
		if (spawn_one_cmd(ms, p, &in_fd, &last_pid) == -1)
			return (-1);
		p = p->next;
	}
	if (in_fd != -1)
		close(in_fd);
	return (last_pid);
}
