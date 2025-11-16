/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:19:04 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:18:19 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	tok_type(const char *s)
{
	if (ft_strcmp(s, "|") == 0)
		return (T_PIPE);
	if (ft_strcmp(s, "<") == 0)
		return (T_LT);
	if (ft_strcmp(s, ">") == 0)
		return (T_GT);
	if (ft_strcmp(s, ">>") == 0)
		return (T_DGT);
	if (ft_strcmp(s, "<<") == 0)
		return (T_DLT);
	return (T_WORD);
}

t_redir	*rd_new(int t, char *a)
{
	t_redir	*r;

	r = malloc(sizeof(t_redir));
	if (!r)
		return (NULL);
	r->type = t;
	r->arg = a;
	r->next = NULL;
	return (r);
}

void	rd_add(t_redir **rd, t_redir **rt, t_redir *rn)
{
	if (!*rd)
		*rd = rn;
	else
		(*rt)->next = rn;
	*rt = rn;
}
