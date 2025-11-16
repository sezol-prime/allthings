/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:16:28 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:16:36 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_free_array(char **arry, int count)
{
	int	i;

	if (!arry)
		return (0);
	i = 0;
	while (i < count)
		free(arry[i++]);
	free(arry);
	return (0);
}

int	ft_array_len(char **arr)
{
	int	count;

	count = 0;
	if (!arr)
		return (0);
	while (arr[count])
		count++;
	return (count);
}
