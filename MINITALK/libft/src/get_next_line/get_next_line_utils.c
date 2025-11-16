/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:04:03 by sitao             #+#    #+#             */
/*   Updated: 2025/03/02 21:57:45 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	char	*dup;
	int		i;

	if (!s)
	{
		dup = (char *)malloc(1);
		if (!dup)
			return (NULL);
		dup[0] = '\0';
		return (dup);
	}
	dup = (char *)malloc(gnl_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = gnl_strdup("");
	if (!s1)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	actual_len;

	if (!s || start >= gnl_strlen(s))
		return (gnl_strdup(""));
	actual_len = gnl_strlen(s) - start;
	if (actual_len > len)
		actual_len = len;
	substr = (char *)malloc(actual_len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < actual_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	printf("%s\n", gnl_strchr("heelo", '\0'));
	printf("%s\n", gnl_strjoin(NULL, NULL));
}*/
