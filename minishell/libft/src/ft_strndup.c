/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:47:00 by mipang            #+#    #+#             */
/*   Updated: 2025/11/03 00:47:10 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	m;
	size_t	i;
	char	*p;

	m = 0;
	while (m < n && s[m])
		m++;
	p = malloc(m + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < m)
	{
		p[i] = s[i];
		i++;
	}
	p[m] = 0;
	return (p);
}
