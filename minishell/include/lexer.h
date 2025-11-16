/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:53:21 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:02:24 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

int		is_space(int c);
char	*take_word(const char *s, size_t *i);
char	*take_word_loop(const char *s, size_t *i, size_t st);
char	*take_op(const char *s, size_t *i, t_tok *t);
char	*take_op_single(const char *s, size_t *i, t_tok *t);
char	*take_op_double(const char *s, size_t *i, t_tok *t);
int		lex_step(const char *s, size_t *i, t_vec *out);
int		ms_lex(const char *s, t_vec *out);
void	ms_tokens_free(t_vec *v);

#endif
