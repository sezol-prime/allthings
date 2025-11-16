/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:07:01 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 18:01:41 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int		tok_type(const char *s);
t_redir	*rd_new(int t, char *a);
void	rd_add(t_redir **rd, t_redir **rt, t_redir *rn);
int		parse_collect(char **t, size_t *i,
			t_vec *args, t_redir **rd);
int		parse_redir(char **t, size_t *i, t_vec *args, t_redir **rd);
int		parse_build_cmd(t_vec *args, t_redir *rd, t_cmd **out);
int		parse_cmd(char **t, size_t *i, t_cmd **out);
void	ms_cmd_free(t_cmd *c);
int		ms_parse(t_vec *toks, t_cmd **pipeline);

#endif
