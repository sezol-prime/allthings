/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:08:23 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:16:26 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static t_env	*node(const char *k, const char *v)
{
	t_env	*e;

	e = malloc(sizeof(t_env));
	if (e == NULL)
		return (NULL);
	e->key = ft_strdup(k);
	if (v != NULL)
		e->val = ft_strdup(v);
	else
		e->val = NULL;
	e->next = NULL;
	return (e);
}

t_env	*make_node_from_entry(const char *entry)
{
	t_env	*n;
	char	*eq;
	char	*tmpk;

	n = NULL;
	eq = ft_strchr(entry, '=');
	if (eq != NULL)
	{
		tmpk = ft_substr(entry, 0, (size_t)(eq - entry));
		if (tmpk == NULL)
			return (NULL);
		n = node(tmpk, eq + 1);
		free(tmpk);
	}
	else
		n = node(entry, NULL);
	return (n);
}
