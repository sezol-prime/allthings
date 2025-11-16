/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:14:47 by sitao             #+#    #+#             */
/*   Updated: 2024/12/23 22:49:50 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char src[11] = "Hello42!";
    char dst[11] = "Nihao24!";

    ft_memcpy(dst, src, 9);
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return 0;
}
*/
