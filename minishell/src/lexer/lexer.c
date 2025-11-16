/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:05:24 by mipang            #+#    #+#             */
/*   Updated: 2025/11/07 01:10:20 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ms_lex(const char *s, t_vec *out)
{
	size_t	i;
	int		r;

	i = 0;
	while (s[i])
	{
		r = lex_step(s, &i, out);
		if (r != 0)
		{
			if (r == -2)
				return (-2);
			return (1);
		}
	}
	return (0);
}

void	ms_tokens_free(t_vec *v)
{
	vec_free(v);
}
