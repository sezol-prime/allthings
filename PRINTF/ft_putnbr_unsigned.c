/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:02:24 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:02:26 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static	int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long	num;
	int		count;

	count = 0;
	num = (long)n;
	if (num >= 10)
		count += ft_putnbr_unsigned(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}
/*#include <stdio.h>
#include <limits.h>

int     main(void)
{
        int     test1 = 10;
      
        int     test3 = 100;
        int     test5 = 101;
        ft_putnbr_unsigned(test1);
        write(1, "\n", 1);
        printf("%u\n", test1);
        ft_putnbr_unsigned(test3);
        write(1, "\n", 1);
        printf("%u\n", test3);
        ft_putnbr_unsigned(test5);
        write(1, "\n", 1);
        printf("%u\n", test5);

}*/
