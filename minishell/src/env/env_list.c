/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:08:50 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:16:23 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	env_append(t_env **head, t_env **tail, t_env *n)
{
	if (*head == NULL)
		*head = n;
	else
		(*tail)->next = n;
	*tail = n;
}

t_env	*env_from(char **envp)
{
	size_t	i;
	t_env	*h;
	t_env	*t;
	t_env	*n;

	h = NULL;
	t = NULL;
	i = 0;
	while (envp != NULL && envp[i] != NULL)
	{
		n = make_node_from_entry(envp[i]);
		if (n == NULL)
		{
			env_free(h);
			return (NULL);
		}
		env_append(&h, &t, n);
		i++;
	}
	return (h);
}

void	env_free(t_env *e)
{
	t_env	*nxt;

	while (e)
	{
		nxt = e->next;
		free(e->key);
		free(e->val);
		free(e);
		e = nxt;
	}
}
