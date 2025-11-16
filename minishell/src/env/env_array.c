/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:09:37 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:16:10 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static size_t	count_env(t_env *e)
{
	size_t	n;

	n = 0;
	while (e != NULL)
	{
		n++;
		e = e->next;
	}
	return (n);
}

static char	*make_env_entry(t_env *p)
{
	char	*k;
	char	*res;

	if (p->val != NULL)
	{
		k = ft_strjoin(p->key, "=");
		if (k == NULL)
			return (NULL);
		res = ft_strjoin(k, p->val);
		free(k);
		return (res);
	}
	res = ft_strdup(p->key);
	return (res);
}

char	**env_to_array(t_env *e)
{
	size_t	n;
	size_t	i;
	t_env	*p;
	char	**a;

	n = count_env(e);
	a = (char **)malloc(sizeof(char *) * (n + 1));
	if (a == NULL)
		return (NULL);
	p = e;
	i = 0;
	while (p != NULL)
	{
		a[i] = make_env_entry(p);
		i++;
		p = p->next;
	}
	a[n] = NULL;
	return (a);
}
