/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:01:14 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:01:18 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int	handle_format(char format, va_list args)
{
	if (format == '%')
		return (write(1, "%%", 1));
	else if (format == 'c')
		return (ft_putchar_utils(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_utils(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_utils(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex_utils(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_putptr_utils(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			else
				count += handle_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
