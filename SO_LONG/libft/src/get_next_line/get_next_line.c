/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:04:24 by sitao             #+#    #+#             */
/*   Updated: 2025/03/02 21:44:47 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*read_loop(int fd, char *buf, char *rem);
static	char	*read_to_rem(int fd, char *rem);
static	char	*get_line(char *rem);
static	char	*update_rem(char *rem);

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rem)
	{
		rem = gnl_strdup("");
		if (!rem)
			return (NULL);
	}
	rem = read_to_rem(fd, rem);
	if (!rem)
		return (NULL);
	line = get_line(rem);
	tmp = update_rem(rem);
	free(rem);
	rem = tmp;
	return (line);
}

static char	*read_to_rem(int fd, char *rem)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(rem);
		return (NULL);
	}
	rem = read_loop(fd, buf, rem);
	return (rem);
}

static	char	*read_loop(int fd, char *buf, char *rem)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (!gnl_strchr(rem, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(rem);
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		tmp = rem;
		rem = gnl_strjoin(tmp, buf);
		if (!rem)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(buf);
	return (rem);
}

static	char	*get_line(char *rem)
{
	size_t	i;
	char	*line;

	if (!rem || rem[0] == '\0')
		return (NULL);
	i = 0;
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	if (rem[i] == '\n')
		i++;
	line = gnl_substr(rem, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static	char	*update_rem(char *rem)
{
	size_t	i;
	char	*new_rem;

	if (!rem)
		return (NULL);
	i = 0;
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	if (rem[i] == '\0')
		return (NULL);
	new_rem = gnl_substr(rem, i + 1, gnl_strlen(rem) - (i + 1));
	if (!new_rem)
		return (NULL);
	return (new_rem);
}
