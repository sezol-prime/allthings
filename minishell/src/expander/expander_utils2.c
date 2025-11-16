/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:52:37 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:03:06 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static size_t	vec_total_len(t_vec *out)
{
	size_t	tot;
	size_t	x;

	tot = 0;
	x = 0;
	while (x < out->len)
	{
		tot = tot + ft_strlen(out->data[x]);
		x++;
	}
	return (tot);
}

static void	fill_buf(char *r, t_vec *out)
{
	size_t	pos;
	size_t	x;
	size_t	j;
	size_t	len;

	pos = 0;
	x = 0;
	while (x < out->len)
	{
		j = 0;
		len = ft_strlen(out->data[x]);
		while (j < len)
		{
			r[pos] = ((char **)out->data)[x][j];
			pos++;
			j++;
		}
		x++;
	}
	r[pos] = 0;
}

char	*join_vec_to_str(t_vec *out)
{
	size_t	tot;
	char	*r;

	tot = vec_total_len(out);
	r = (char *)malloc(tot + 1);
	if (!r)
		return (NULL);
	fill_buf(r, out);
	return (r);
}
