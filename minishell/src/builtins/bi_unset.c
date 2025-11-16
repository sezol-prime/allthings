/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:34:23 by mipang            #+#    #+#             */
/*   Updated: 2025/10/29 00:01:30 by mipang           ###   ########.fr       */
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

int	bi_unset(t_ms *ms, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (valid_key(argv[i]) != 0)
			env_unset(&ms->env, argv[i]);
		i++;
	}
	return (0);
}
