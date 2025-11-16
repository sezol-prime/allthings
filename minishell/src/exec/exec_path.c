/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:28 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:17:30 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*build_full_path(const char *path,
				size_t start,
				size_t len,
				const char *cmd)
{
	char	*dir;
	char	*tmp;
	char	*full;

	dir = ft_substr(path, start, len);
	if (dir == NULL)
		return (NULL);
	tmp = ft_strjoin(dir, "/");
	if (tmp == NULL)
	{
		free(dir);
		return (NULL);
	}
	full = ft_strjoin(tmp, cmd);
	free(dir);
	free(tmp);
	return (full);
}

static char	*search_in_path(char *p, const char *cmd)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*full;

	i = 0;
	n = ft_strlen(p);
	while (i <= n)
	{
		j = i;
		while (p[j] != '\0' && p[j] != ':')
			j++;
		full = build_full_path(p, i, j - i, cmd);
		if (full != NULL && access(full, X_OK) == 0)
			return (full);
		free(full);
		if (p[j] == '\0')
			break ;
		i = j + 1;
	}
	return (NULL);
}

char	*find_cmd(t_env *env, const char *cmd)
{
	char	*p;

	if (ft_strchr(cmd, '/') != NULL)
		return (ft_strdup(cmd));
	p = env_get(env, "PATH");
	if (p == NULL || *p == '\0')
		return (NULL);
	return (search_in_path(p, cmd));
}
