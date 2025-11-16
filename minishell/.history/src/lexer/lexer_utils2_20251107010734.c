/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:08:35 by mipang            #+#    #+#             */
/*   Updated: 2025/11/07 01:07:34 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*take_op_single(const char *s, size_t *i, t_tok *t)
{
	if (s[*i] == '|')
	{
		*t = T_PIPE;
		*i = *i + 1;
		return (ft_strdup("|"));
	}
	if (s[*i] == '<')
	{
		*t = T_LT;
		*i = *i + 1;
		return (ft_strdup("<"));
	}
	if (s[*i] == '>')
	{
		*t = T_GT;
		*i = *i + 1;
		return (ft_strdup(">"));
	}
	return (NULL);
}

char	*take_op(const char *s, size_t *i, t_tok *t)
{
	char	*w;

	w = take_op_double(s, i, t);
	if (w)
		return (w);
	return (take_op_single(s, i, t));
}

int	lex_step(const char *s, size_t *i, t_vec *out)
{
	t_tok	t;
	char	*w;

	if (is_space(s[*i]))
	{
		*i = *i + 1;
		return (0);
	}
	if (s[*i] == '|' || s[*i] == '<' || s[*i] == '>')
	{
		w = take_op(s, i, &t);
		if (!w)
			return (1);
		vec_push(out, w);
		return (0);
	}
	w = take_word(s, i);
	if (!w)
		return (-2);
	vec_push(out, w);
	return (0);
}

