/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:30:47 by sitao             #+#    #+#             */
/*   Updated: 2024/12/24 23:51:26 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t	len;
	long	num;

	num = (long)n;
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 10)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	size_t	len;

	num = (long)n;
	len = count_len(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memset(result, 0, len + 1);
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (len > 0 && result[len -1] != '-')
	{
		result[len - 1] = (num % 10) + '0';
		num /= 10;
		len --;
	}
	return (result);
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    int numbers[] = {123, -123, 0, 2147483647, -2147483648};
    char *result;

    for (int i = 0; i < 5; i++)
    {
        result = ft_itoa(numbers[i]);
        if (result)
        {
            printf("ft_itoa(%d) = %s\n", numbers[i], result);
            free(result); // 释放内存
        }
        else
        {
            printf("Memory allocation failed for %d\n", numbers[i]);
        }
    }
    return (0);
}
*/
