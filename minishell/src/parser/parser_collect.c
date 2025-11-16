/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:19:31 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:09:31 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_redir_err(t_vec *args)
{
	vec_free(args);
	return (1);
}

static int	parse_redir_inner(char **t, size_t *i,
		t_vec *args, t_redir **rd)
{
	int				tp;
	t_redir			*rn;
	static t_redir	*rt;

	tp = tok_type(t[*i]);
	*i = *i + 1;
	if (!t[*i])
		return (parse_redir_err(args));
	rn = rd_new(tp, ft_strdup(t[*i]));
	if (!rn)
		return (parse_redir_err(args));
	rd_add(rd, &rt, rn);
	*i = *i + 1;
	return (0);
}

int	parse_redir(char **t, size_t *i, t_vec *args, t_redir **rd)
{
	return (parse_redir_inner(t, i, args, rd));
}

int	parse_collect(char **t, size_t *i, t_vec *args, t_redir **rd)
{
	if (tok_type(t[*i]) == T_WORD)
	{
		vec_push(args, ft_strdup(t[*i]));
		*i = *i + 1;
		return (0);
	}
	if (parse_redir(t, i, args, rd) != 0)
		return (1);
	return (0);
}
