/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:28:44 by sitao             #+#    #+#             */
/*   Updated: 2024/12/23 22:35:08 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count > 0 && size > 0 && count > (size_t)(-1) / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset (ptr, 0, count * size);
	return (ptr);
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    int *array;
    size_t count = 5;
    size_t size = sizeof(int);

    array = (int *)ft_calloc(count, size);
    if (!array)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }
    for (size_t i = 0; i < count; i++)
        printf("array[%zu] = %d\n", i, array[i]);

    free(array); // 释放内存
    return (0);
}
*/
