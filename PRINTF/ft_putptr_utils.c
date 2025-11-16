/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:03:09 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:03:11 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>

static	void	*ft_memset(void *s, int c, size_t n)
{	
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}

static int	ft_puthex_x(unsigned long num)
{
	const char	*base;
	char		result[17];
	int			i;
	int			count;

	base = "0123456789abcdef";
	if (num == 0)
		return (write(1, "0", 1));
	ft_memset(result, 0, sizeof(result));
	i = 0;
	while (num != 0)
	{
		result[i++] = base[num % 16];
		num /= 16;
	}
	count = 0;
	while (i > 0)
		count += write(1, &result[--i], 1);
	return (count);
}

int	ft_putptr_utils(void *ptr)
{
	long	n;
	int		count;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	n = (unsigned long)ptr;
	count += ft_puthex_x(n);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	void	*test = (void *)NULL;
	ft_putptr_utils(test);
	printf("\n%p\n", test);
}*/
