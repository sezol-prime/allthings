/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:09:16 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:16:20 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_get(t_env *e, const char *key)
{
	while (e != NULL)
	{
		if (ft_strcmp(e->key, key) == 0)
		{
			if (e->val != NULL)
				return (e->val);
			return ("");
		}
		e = e->next;
	}
	return (NULL);
}

static int	env_overwrite(t_env *p, const char *val, int overwrite)
{
	if (overwrite == 0)
		return (0);
	free(p->val);
	if (val != NULL)
		p->val = ft_strdup(val);
	else
		p->val = NULL;
	return (0);
}

int	env_set(t_env **e, const char *key, const char *val, int overwrite)
{
	t_env	*p;

	p = *e;
	while (p != NULL)
	{
		if (ft_strcmp(p->key, key) == 0)
			return (env_overwrite(p, val, overwrite));
		p = p->next;
	}
	p = make_node_from_entry(key);
	if (!p)
		return (1);
	free(p->val);
	if (val != NULL)
		p->val = ft_strdup(val);
	else
		p->val = NULL;
	p->next = *e;
	*e = p;
	return (0);
}

int	env_unset(t_env **e, const char *key)
{
	t_env	*p;
	t_env	*prev;

	p = *e;
	prev = NULL;
	while (p)
	{
		if (ft_strcmp(p->key, key) == 0)
		{
			if (prev)
				prev->next = p->next;
			else
				*e = p->next;
			free(p->key);
			free(p->val);
			free(p);
			return (0);
		}
		prev = p;
		p = p->next;
	}
	return (0);
}
