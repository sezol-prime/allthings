/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:03:25 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:03:32 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>

int	ft_putstr_utils(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/*#include <stdio.h>
int	main(void)
{
	char	*test0 = "\0";
	char	*test1 = "";
	char	*test2 = NULL;
	char	*test3 = "HELLO, WORLD!$$$$";
	ft_putstr_utils(test0);
	printf("%s\n", test0);
	ft_putstr_utils(test1);
	printf("%s\n", test1);
	ft_putstr_utils(test2);
	printf("%s\n", test2);
	ft_putstr_utils(test3);
	printf("%s\n", test3);	
}*/
