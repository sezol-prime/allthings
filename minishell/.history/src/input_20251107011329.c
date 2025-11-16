/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:58:57 by mipang            #+#    #+#             */
/*   Updated: 2025/11/07 01:13:29 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_blank(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\t'
				|| s[i] == '\n' || s[i] == '\r'
				|| s[i] == '\v' || s[i] == '\f'))
			return (0);
		i++;
	}
	return (1);
}

char	*ms_readline(void)
{
	char	*s;

	s = readline("minishell$ ");
	if (!s)
		return (NULL);
	if (*s)
		add_history(s);
	return (s);
}

static int	handle_line(t_ms *ms, char *line)
{
	t_vec	toks;
	t_cmd	*p;
	int		r;

	vec_init(&toks);
	r = ms_lex(line, &toks);
	if (r == -2)
	{
		write(2, "minishell: syntax error: unclosed quote\n", 39);
		set_status(ms, 258);
		ms_tokens_free(&toks);
		return (0);
	}
	if (r == 0
		&& ms_expand_line(ms, &toks) == 0
		&& ms_parse(&toks, &p) == 0)
	{
		if (p)
		{
			set_status(ms, ms_exec(ms, p));
			ms_cmd_free(p);
		}
	}
	ms_tokens_free(&toks);
	return (0);
}

int	ms_loop(t_ms *ms)
{
	char	*line;

	while (1)
	{
		line = ms_readline();
		if (!line)
		{
			if (get_status(ms) == 130)
			{
				set_status(ms, 0);
				continue ;
			}
			break ;
		}
		if (is_blank(line))
		{
			free(line);
			continue ;
		}
		handle_line(ms, line);
		free(line);
	}
	return (0);
}
