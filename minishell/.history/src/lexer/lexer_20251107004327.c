/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:05:24 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:15:34 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ms_lex(const char *s, t_vec *out)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (lex_step(s, &i, out) != 0)
			return (1);
	}
	return (0);
}

void	ms_tokens_free(t_vec *v)
{
	vec_free(v);
}
