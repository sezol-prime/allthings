/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:34:30 by mipang            #+#    #+#             */
/*   Updated: 2025/10/28 23:43:02 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*get_cd_path(t_ms *ms, char **argv)
{
	int			i;
	const char	*home;

	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
	{
		write(2, "cd: too many arguments\n", 23);
		return (NULL);
	}
	if (!argv[1])
	{
		home = env_get(ms->env, "HOME");
		if (!home || !*home)
		{
			write(2, "cd: HOME not set\n", 17);
			return (NULL);
		}
		return (home);
	}
	return (argv[1]);
}

static void	update_pwd_env(t_ms *ms, char *old, char *cwd)
{
	if (!getcwd(cwd, 4096))
		return ;
	if (old[0])
		env_set(&ms->env, "OLDPWD", old, 1);
	else
		env_set(&ms->env, "OLDPWD", NULL, 1);
	env_set(&ms->env, "PWD", cwd, 1);
}

int	bi_cd(t_ms *ms, char **argv)
{
	const char	*path;
	char		old[4096];
	char		cwd[4096];

	path = get_cd_path(ms, argv);
	if (!path)
		return (1);
	if (!getcwd(old, 4096))
		old[0] = '\0';
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	update_pwd_env(ms, old, cwd);
	return (0);
}
