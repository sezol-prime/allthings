/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:01:44 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:01:46 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar_utils(char c)
{
	write(1, &c, 1);
	return (1);
}
/*#include <stdio.h>
int main (void)
{
	char test = '%';
	ft_putchar_utils(test);
	printf("%c\n", test);
}*/
