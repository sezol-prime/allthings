/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:34:47 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 21:21:55 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_nopt(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	if (s[0] != '-')
		return (0);
	if (s[1] != 'n')
		return (0);
	i = 2;
	while (s[i] != '\0')
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	bi_echo(char **argv)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	if (is_nopt(argv[1]) != 0)
	{
		nl = 0;
		i++;
		while (is_nopt(argv[i]) != 0)
			i++;
	}
	while (argv[i] != NULL)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	if (nl != 0)
		write(1, "\n", 1);
	return (0);
}
