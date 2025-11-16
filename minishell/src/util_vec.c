/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:01:37 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:06:23 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	vec_init(t_vec *v)
{
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}

static int	ensure_cap(t_vec *v)
{
	char	**n;
	size_t	c;
	size_t	i;

	if (v->len + 1 < v->cap)
		return (1);
	if (v->cap == 0)
		c = 8;
	else
		c = v->cap * 2;
	n = malloc(sizeof(char *) * c);
	if (!n)
		return (0);
	i = 0;
	while (i < v->len)
	{
		n[i] = v->data[i];
		i++;
	}
	free(v->data);
	v->data = n;
	v->cap = c;
	return (1);
}

void	vec_push(t_vec *v, char *s)
{
	if (!ensure_cap(v))
		return ;
	v->data[v->len] = s;
	v->len = v->len + 1;
	v->data[v->len] = NULL;
}

void	vec_free(t_vec *v)
{
	size_t	i;

	i = 0;
	if (!v->data)
		return ;
	while (i < v->len)
	{
		free(v->data[i]);
		i++;
	}
	free(v->data);
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}

char	**vec_dup(char **a)
{
	size_t	n;
	size_t	i;
	char	**b;

	n = 0;
	while (a && a[n])
		n++;
	b = malloc(sizeof(char *) * (n + 1));
	if (!b)
		return (NULL);
	i = 0;
	while (i < n)
	{
		b[i] = ft_strdup(a[i]);
		i++;
	}
	b[n] = NULL;
	return (b);
}
