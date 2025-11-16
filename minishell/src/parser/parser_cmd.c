/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:20:23 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:45:04 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_cmd(char **t, size_t *i, t_cmd **out)
{
	t_vec	args;
	t_redir	*rd;
	int		res;

	vec_init(&args);
	rd = NULL;
	while (t[*i] && ft_strcmp(t[*i], "|") != 0)
	{
		if (parse_collect(t, i, &args, &rd) != 0)
			return (1);
	}
	res = parse_build_cmd(&args, rd, out);
	if (res != 0)
		return (res);
	return (0);
}
