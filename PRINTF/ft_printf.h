/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:01:30 by sitao             #+#    #+#             */
/*   Updated: 2025/02/25 23:01:32 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_utils(char c);
int	ft_putstr_utils(char *str);
int	ft_putnbr_utils(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex_utils(unsigned long n, const char format);
int	ft_putptr_utils(void *ptr);

#endif
