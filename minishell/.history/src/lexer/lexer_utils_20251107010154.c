/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:08:13 by mipang            #+#    #+#             */
/*   Updated: 2025/11/07 01:01:54 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_space(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*take_word_loop(const char *s, size_t *i, size_t st)
{
	int	sq;
	int	dq;

	sq = 0;
	dq = 0;
	while (s[*i])
	{
		if (!sq && !dq && (is_space(s[*i])
				|| s[*i] == '|' || s[*i] == '<' || s[*i] == '>'))
			break ;
		if (s[*i] == '\'' && !dq)
			sq = sq ^ 1;
		else if (s[*i] == '\"' && !sq)
			dq = dq ^ 1;
		*i = *i + 1;
	}
	if (sq || dq)
		return (NULL);
	return (ft_substr(s, st, *i - st));
}

char	*take_word(const char *s, size_t *i)
{
	size_t	st;

	st = *i;
	return (take_word_loop(s, i, st));
}

char	*take_op_double(const char *s, size_t *i, t_tok *t)
{
	if (s[*i] == '<' && s[*i + 1] == '<')
	{
		*t = T_DLT;
		*i = *i + 2;
		return (ft_strdup("<<"));
	}
	if (s[*i] == '>' && s[*i + 1] == '>')
	{
		*t = T_DGT;
		*i = *i + 2;
		return (ft_strdup(">>"));
	}
	return (NULL);
}

