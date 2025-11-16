/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:04:49 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 19:21:27 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

void	child_setup_fds(int in_fd, int out_fd);
void	child_exit_not_found(char **argv, char **envp);
void	child_exec_error(char **argv, char **envp, char *path);
void	child_try_builtin(t_ms *ms, t_cmd *c);
void	child_empty_argv(char **envp);
int		exec_child(t_ms *ms, t_cmd *c, int in_fd, int out_fd);
char	*find_cmd(t_env *env, const char *cmd);
int		single_parent_builtin(t_ms *ms, t_cmd *c);
int		count_cmds(t_cmd *p);
int		is_parent_only_builtin(t_cmd *p);
pid_t	spawn_pipeline(t_ms *ms, t_cmd *p);
int		wait_and_get_status(pid_t last_pid);
int		ms_exec(t_ms *ms, t_cmd *p);

#endif
