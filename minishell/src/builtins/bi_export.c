/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:35:06 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 20:00:50 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_key(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	if (!(ft_isalpha((unsigned char)s[0]) || s[0] == '_'))
		return (0);
	i = 1;
	while (s[i] != '\0')
	{
		if (!(ft_isalnum((unsigned char)s[i]) || s[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static int	handle_export_assign(t_ms *ms, const char *arg)
{
	char	*eq;
	char	*k;
	char	*v;

	eq = ft_strchr(arg, '=');
	k = ft_substr(arg, 0, eq - arg);
	v = ft_strdup(eq + 1);
	if (valid_key(k) != 0)
		env_set(&ms->env, k, v, 1);
	else
	{
		write(2, "export: not a valid identifier\n", 31);
		free(k);
		free(v);
		return (1);
	}
	free(k);
	free(v);
	return (0);
}

static int	handle_export_name(t_ms *ms, const char *arg)
{
	if (valid_key(arg) != 0)
	{
		env_set(&ms->env, arg, NULL, 0);
		return (0);
	}
	write(2, "export: not a valid identifier\n", 31);
	return (1);
}

int	bi_export(t_ms *ms, char **argv)
{
	int		i;
	char	*eq;

	i = 1;
	if (argv[1] == NULL)
		return (bi_env(ms->env));
	while (argv[i] != NULL)
	{
		eq = ft_strchr(argv[i], '=');
		if (eq != NULL)
		{
			if (handle_export_assign(ms, argv[i]) != 0)
				return (1);
		}
		else
		{
			if (handle_export_name(ms, argv[i]) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}
