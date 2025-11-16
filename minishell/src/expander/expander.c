/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:53:12 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:03:09 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	token_is_op(char *s)
{
	if (ft_strcmp(s, "|") == 0)
		return (1);
	if (ft_strcmp(s, "<") == 0)
		return (1);
	if (ft_strcmp(s, ">") == 0)
		return (1);
	if (ft_strcmp(s, ">>") == 0)
		return (1);
	if (ft_strcmp(s, "<<") == 0)
		return (1);
	return (0);
}

static void	process_char(t_ctx *c)
{
	if (c->s[c->i] == '\'' && c->dq == 0)
	{
		c->sq = c->sq ^ 1;
		c->i = c->i + 1;
		return ;
	}
	if (c->s[c->i] == '\"' && c->sq == 0)
	{
		c->dq = c->dq ^ 1;
		c->i = c->i + 1;
		return ;
	}
	if (c->s[c->i] == '$' && c->sq == 0)
	{
		if (handle_dollar(c->ms, c->s, &c->i, c->out))
			return ;
	}
	vec_push(c->out, ft_strndup(c->s + c->i, 1));
	c->i = c->i + 1;
}

static int	expand_loop(t_ms *ms, const char *s, t_vec *out)
{
	t_ctx	c;

	c.i = 0;
	c.sq = 0;
	c.dq = 0;
	c.out = out;
	c.ms = ms;
	c.s = s;
	while (s[c.i])
		process_char(&c);
	return (0);
}

static char	*expand_once(t_ms *ms, const char *s)
{
	t_vec	out;
	char	*res;

	vec_init(&out);
	if (expand_loop(ms, s, &out) != 0)
	{
		vec_free(&out);
		return (NULL);
	}
	res = join_vec_to_str(&out);
	vec_free(&out);
	return (res);
}

int	ms_expand_line(t_ms *ms, t_vec *toks)
{
	size_t	i;
	char	*e;

	i = 0;
	while (i < toks->len)
	{
		if (!token_is_op(toks->data[i]))
		{
			e = expand_once(ms, toks->data[i]);
			if (!e)
				return (1);
			free(toks->data[i]);
			toks->data[i] = e;
		}
		i++;
	}
	return (0);
}
