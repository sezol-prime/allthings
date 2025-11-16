/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:06:41 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:21:56 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

typedef struct s_ctx
{
	size_t		i;
	int			sq;
	int			dq;
	t_vec		*out;
	t_ms		*ms;
	const char	*s;
}	t_ctx;

typedef struct s_bounds
{
	size_t	j;
	size_t	k;
	int		br;
}	t_bounds;

int		is_var_start(char c);
int		push_status_var(t_ms *ms, size_t *i, t_vec *out);
int		push_env_var(t_ms *ms, const char *s, size_t *i, t_vec *out);
int		handle_dollar(t_ms *ms, const char *s, size_t *i, t_vec *out);
char	*join_vec_to_str(t_vec *out);
int		ms_expand_line(t_ms *ms, t_vec *toks);

#endif
