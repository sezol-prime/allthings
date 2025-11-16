/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:19:57 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 18:00:52 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_redir_list(t_redir *r)
{
	t_redir	*nx;

	while (r)
	{
		nx = r->next;
		free(r->arg);
		free(r);
		r = nx;
	}
}

static char	**alloc_argv(t_vec *args)
{
	char	**argv;

	argv = (char **)args->data;
	if (!argv)
	{
		argv = (char **)malloc(sizeof(char *));
		if (!argv)
			return (NULL);
		argv[0] = NULL;
	}
	return (argv);
}

static int	validate_cmd_nostate(t_cmd *c)
{
	if ((!c->argv || !c->argv[0]) && c->rd == NULL)
	{
		write(2, "syntax error near unexpected token `|'\n", 39);
		if (c->argv)
			free(c->argv);
		free_redir_list(c->rd);
		free(c);
		return (2);
	}
	return (0);
}

int	parse_build_cmd(t_vec *args, t_redir *rd, t_cmd **out)
{
	t_cmd	*c;
	int		err;

	c = (t_cmd *)malloc(sizeof(t_cmd));
	if (!c)
	{
		vec_free(args);
		return (1);
	}
	c->argv = alloc_argv(args);
	if (!c->argv)
		return (1);
	c->rd = rd;
	c->next = NULL;
	err = validate_cmd_nostate(c);
	if (err != 0)
		return (err);
	*out = c;
	return (0);
}
