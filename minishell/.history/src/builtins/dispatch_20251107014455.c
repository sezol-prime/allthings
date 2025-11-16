/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:35:24 by mipang            #+#    #+#             */
/*   Updated: 2025/11/07 01:44:55 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_echo(char **argv);
int	bi_pwd(void);
int	bi_env(t_env *e);
int	bi_cd(t_ms *ms, char **argv);
int	bi_export(t_ms *ms, char **argv);
int	bi_unset(t_ms *ms, char **argv);
int	bi_exit(t_ms *ms, char **argv);

static int	arg_count(char **argv)
{
	int	n;

	n = 0;
	while (argv && argv[n])
		n++;
	return (n);
}

static int	run_builtin_core(t_ms *ms, char **argv)
{
	int	ac;

	if (argv == NULL || argv[0] == NULL)
		return (0);
	if (ft_strcmp(argv[0], "echo") == 0)
		return (bi_echo(argv));
	if (ft_strcmp(argv[0], "pwd") == 0)
	{
		ac = arg_count(argv);
		if (ac > 1)
		{
			if (argv[1][0] == '-')
			{
				write(2, "pwd: invalid option\n", 20);
				return (2);
			}
			write(2, "pwd: too many arguments\n", 24);
			return (1);
		}
		return (bi_pwd());
	}
	if (ft_strcmp(argv[0], "env") == 0)
	{
		if (arg_count(argv) != 1)
		{
			write(2, "env: too many arguments\n", 24);
			return (1);
		}
		return (bi_env(ms->env));
	}
	if (ft_strcmp(argv[0], "cd") == 0)
		return (bi_cd(ms, argv));
	if (ft_strcmp(argv[0], "export") == 0)
		return (bi_export(ms, argv));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (bi_unset(ms, argv));
	if (ft_strcmp(argv[0], "exit") == 0)
		return (bi_exit(ms, argv));
	return (0);
}

int	is_builtin(const char *s)
{
	int			i;
	const char	*names[] = {
		"echo", "pwd", "env", "cd", "export", "unset", "exit", NULL
	};

	if (s == NULL)
		return (0);
	i = 0;
	while (names[i] != NULL)
	{
		if (ft_strcmp(s, names[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	run_builtin_child(t_ms *ms, t_cmd *c)
{
	if (c == NULL)
		return (0);
	return (run_builtin_core(ms, c->argv));
}

int	run_builtin_parent(t_ms *ms, t_cmd *c)
{
	if (c == NULL)
		return (0);
	return (run_builtin_core(ms, c->argv));
}
