/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:27:25 by sitao             #+#    #+#             */
/*   Updated: 2024/12/24 03:01:53 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_next_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_substr(s, 0, i));
}

static void	free_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	fill_result(char **result, const char *s, char c, size_t word_count)
{
	size_t	i;

	i = 0;
	while (*s && i < word_count)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			result[i] = get_next_word(s, c);
		if (!result[i])
		{
			free_array(result, i);
			return (0);
		}
		s += ft_strlen(result[i]);
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c, word_count))
		return (NULL);
	result[word_count] = NULL;
	return (result);
}
