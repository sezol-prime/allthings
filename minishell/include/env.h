/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:02:38 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:04:36 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

t_env	*make_node_from_entry(const char *entry);
t_env	*env_from(char **envp);
void	env_free(t_env *e);
char	*env_get(t_env *e, const char *key);
int		env_set(t_env **e, const char *key, const char *val, int overwrite);
int		env_unset(t_env **e, const char *key);
char	**env_to_array(t_env *e);

#endif