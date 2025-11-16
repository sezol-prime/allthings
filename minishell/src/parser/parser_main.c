/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:20:49 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:24:42 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_cmd_node(t_cmd *c)
{
	size_t	i;
	t_redir	*r;
	t_redir	*rn;

	i = 0;
	if (c->argv)
	{
		while (c->argv[i])
		{
			free(c->argv[i]);
			i++;
		}
		free(c->argv);
	}
	r = c->rd;
	while (r)
	{
		rn = r->next;
		free(r->arg);
		free(r);
		r = rn;
	}
	free(c);
}

void	ms_cmd_free(t_cmd *c)
{
	t_cmd	*n;

	while (c)
	{
		n = c->next;
		free_cmd_node(c);
		c = n;
	}
}

static int	parse_one_step(t_vec *toks, size_t *i,
		t_cmd **n, t_cmd **head)
{
	int	r;

	r = parse_cmd((char **)toks->data, i, n);
	if (r != 0)
	{
		if (r == 1 || r == 2)
		{
			ms_cmd_free(*head);
			return (1);
		}
	}
	return (0);
}

static void	link_cmd(t_cmd **head, t_cmd **prev, t_cmd *n)
{
	if (!*head)
		*head = n;
	else
		(*prev)->next = n;
	*prev = n;
}

int	ms_parse(t_vec *toks, t_cmd **pipeline)
{
	size_t	i;
	t_cmd	*h;
	t_cmd	*p;
	t_cmd	*n;

	i = 0;
	h = NULL;
	p = NULL;
	if (toks->len == 0)
		return (0);
	while (i < toks->len)
	{
		if (parse_one_step(toks, &i, &n, &h) != 0)
			return (1);
		link_cmd(&h, &p, n);
		if (i < toks->len && ft_strcmp(toks->data[i], "|") == 0)
			i++;
	}
	*pipeline = h;
	return (0);
}
