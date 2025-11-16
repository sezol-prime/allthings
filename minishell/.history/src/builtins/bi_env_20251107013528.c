/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:34:53 by mipang            #+#    #+#             */
/*   Updated: 2025/11/07 01:35:28 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_env(t_env *e)
{
	while (e != NULL)
	{
		if (e->val != NULL)
		{
			write(1, e->key, ft_strlen(e->key));
			write(1, "=", 1);
			write(1, e->val, ft_strlen(e->val));
			write(1, "\n", 1);
		}
		e = e->next;
	}
	return (0);
}
