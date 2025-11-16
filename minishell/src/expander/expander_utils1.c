/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:51:31 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:02:59 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	is_var_start(char c)
{
	if (c == '_')
		return (1);
	if (ft_isalpha((unsigned char)c))
		return (1);
	return (0);
}

int	push_status_var(t_ms *ms, size_t *i, t_vec *out)
{
	char	*val;

	val = ft_itoa(get_status(ms));
	if (!val)
		return (0);
	vec_push(out, val);
	*i = *i + 2;
	return (1);
}

static void	get_bounds_var(t_bounds *b, const char *s, size_t start)
{
	b->j = start + 1;
	b->br = 0;
	if (s[b->j] == '{')
	{
		b->br = 1;
		b->j = b->j + 1;
	}
	b->k = b->j;
	while (s[b->k]
		&& (s[b->k] == '_' || ft_isalnum((unsigned char)s[b->k])))
	{
		b->k = b->k + 1;
	}
}

int	push_env_var(t_ms *ms, const char *s, size_t *i, t_vec *out)
{
	t_bounds	b;
	char		*key;
	char		*val;

	get_bounds_var(&b, s, *i);
	key = ft_substr(s, b.j, b.k - b.j);
	if (!key)
		return (0);
	val = env_get(ms->env, key);
	if (!val)
		val = "";
	vec_push(out, ft_strdup(val));
	free(key);
	if (b.br && s[b.k] == '}')
		*i = b.k + 1;
	else
		*i = b.k;
	return (1);
}

int	handle_dollar(t_ms *ms, const char *s, size_t *i, t_vec *out)
{
	if (s[*i + 1] == '?')
		return (push_status_var(ms, i, out));
	if (!is_var_start(s[*i + 1]) && s[*i + 1] != '{')
		return (0);
	if (!push_env_var(ms, s, i, out))
		return (0);
	return (1);
}
