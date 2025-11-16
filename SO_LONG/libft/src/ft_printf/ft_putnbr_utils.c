/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:02:54 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:02:56 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static	int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_utils(int n)
{
	long	num;
	int		count;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		count += ft_putnbr_utils(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}

/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	test1 = 10;
	int	test2 = -10;
	int	test3 = 100;
	int	test4 = -100;
	int	test5 = 101;
	int	test6 = -101;
	ft_putnbr_utils(test1);
	write(1, "\n", 1);
	printf("%d\n", test1);
	printf("%i\n", test1);
	ft_putnbr_utils(test2);
	write(1, "\n", 1);
	printf("%d\n", test2);
	printf("%i\n", test2);
	ft_putnbr_utils(test3);
	write(1, "\n", 1);
	printf("%d\n", test3);
	printf("%i\n", test3);
	ft_putnbr_utils(test4);
	write(1, "\n", 1);
	printf("%d\n", test4);
	printf("%i\n", test4);
	ft_putnbr_utils(test5);
	write(1, "\n", 1);
	printf("%d\n", test5);
	printf("%i\n", test5);
	ft_putnbr_utils(test6);
	write(1, "\n", 1);
	printf("%d\n", test6);
	printf("%i\n", test6);
	
}*/
