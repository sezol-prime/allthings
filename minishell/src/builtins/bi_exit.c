/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:35:01 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 21:54:16 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_num(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	bi_exit(t_ms *ms, char **argv)
{
	int	code;

	code = get_status(ms);
	if (argv[1] && is_num(argv[1]) == 0)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		env_free(ms->env);
		exit(2);
	}
	if (argv[1] && argv[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		set_status(ms, 1);
		return (1);
	}
	if (argv[1])
		code = (ft_atoi(argv[1]) & 255);
	if (isatty(STDIN_FILENO))
		write(1, "exit\n", 5);
	env_free(ms->env);
	exit(code);
}
