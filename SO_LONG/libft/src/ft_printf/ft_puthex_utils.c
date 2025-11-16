/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:02:06 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:02:09 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

static	const	char	*ft_base(unsigned char format)
{
	if (format == 'x')
		return ("0123456789abcdef");
	if (format == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

static	void	*ft_local_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}

int	ft_puthex_utils(unsigned long n, const char format)
{
	char		result[17];
	const char	*base;
	int			count;
	int			i;

	if (n == 0)
		return (write(1, "0", 1));
	ft_local_memset(result, 0, sizeof(result));
	base = ft_base(format);
	if (!base)
		return (0);
	i = 0;
	while (n != 0)
	{
		result[i++] = base[n % 16];
		n = n / 16;
	}
	count = 0;
	while (i > 0)
		count += write(1, &result[--i], 1);
	return (count);
}
/*#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	test1 = INT_MAX;
	ft_puthex_utils(test1, 'x');
	write(1, "\n", 1);
	printf("%x\n", test1);
	ft_puthex_utils(test1, 'X');
	write(1, "\n", 1);
	printf("%X\n", test1);
}*/
