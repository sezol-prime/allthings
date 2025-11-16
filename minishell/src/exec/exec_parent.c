/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:17:43 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:17:26 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	restore_fds(int save_in, int save_out)
{
	dup2(save_in, STDIN_FILENO);
	dup2(save_out, STDOUT_FILENO);
	close(save_in);
	close(save_out);
}

int	single_parent_builtin(t_ms *ms, t_cmd *c)
{
	int		save_in;
	int		save_out;
	int		ret;
	char	**argv_copy;
	char	**argv_orig;

	save_in = dup(STDIN_FILENO);
	save_out = dup(STDOUT_FILENO);
	argv_orig = c->argv;
	argv_copy = vec_dup(c->argv);
	ret = ms_redirs_apply(ms, c->rd, 0);
	if (ret != 0)
	{
		restore_fds(save_in, save_out);
		c->argv = argv_orig;
		free_split(argv_copy);
		return (ret);
	}
	c->argv = argv_copy;
	ret = run_builtin_parent(ms, c);
	c->argv = argv_orig;
	restore_fds(save_in, save_out);
	free_split(argv_copy);
	return (ret);
}

static int	count_cmds_step(t_cmd *p, int count)
{
	if (p == NULL)
		return (count);
	return (count_cmds_step(p->next, count + 1));
}

int	count_cmds(t_cmd *p)
{
	return (count_cmds_step(p, 0));
}

int	is_parent_only_builtin(t_cmd *p)
{
	if (p == NULL || p->argv == NULL || p->argv[0] == NULL)
		return (0);
	if (ft_strcmp(p->argv[0], "cd") == 0)
		return (1);
	if (ft_strcmp(p->argv[0], "export") == 0)
		return (1);
	if (ft_strcmp(p->argv[0], "unset") == 0)
		return (1);
	if (ft_strcmp(p->argv[0], "exit") == 0)
		return (1);
	return (0);
}
