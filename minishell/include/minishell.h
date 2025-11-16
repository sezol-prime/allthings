/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:11:51 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 17:41:04 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_vec
{
	char	**data;
	size_t	len;
	size_t	cap;
}	t_vec;

typedef enum e_tok
{
	T_WORD,
	T_PIPE,
	T_LT,
	T_GT,
	T_DGT,
	T_DLT
}	t_tok;

typedef struct s_token
{
	t_tok	type;
	char	*val;
}	t_token;

typedef struct s_redir
{
	int				type;
	char			*arg;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*rd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}	t_env;

typedef struct s_ms
{
	t_env	*env;
	int		last_status;
	int		heredoc_sigint;
}	t_ms;

void	vec_init(t_vec *v);
void	vec_push(t_vec *v, char *s);
void	vec_free(t_vec *v);
char	**vec_dup(char **a);
int		ms_loop(t_ms *ms);
char	*ms_readline(void);
int		ms_lex(const char *s, t_vec *out);
int		ms_parse(t_vec *toks, t_cmd **pipeline);
void	ms_cmd_free(t_cmd *c);
void	ms_tokens_free(t_vec *v);
int		ms_exec(t_ms *ms, t_cmd *p);
int		ms_redirs_apply(t_ms *ms, t_redir *r, int is_child);
int		ms_heredoc_build(t_ms *ms, const char *delim);
int		lex_step(const char *s, size_t *i, t_vec *out);
int		ms_expand_line(t_ms *ms, t_vec *toks);
t_env	*env_from(char **envp);
void	env_free(t_env *e);
char	*env_get(t_env *e, const char *key);
int		env_set(t_env **e, const char *key, const char *val, int overwrite);
int		env_unset(t_env **e, const char *key);
char	**env_to_array(t_env *e);
int		bi_echo(char **argv);
int		bi_pwd(void);
int		bi_env(t_env *e);
int		bi_cd(t_ms *ms, char **argv);
int		bi_export(t_ms *ms, char **argv);
int		bi_unset(t_ms *ms, char **argv);
int		bi_exit(t_ms *ms, char **argv);
int		is_builtin(const char *s);
int		run_builtin_parent(t_ms *ms, t_cmd *c);
int		run_builtin_child(t_ms *ms, t_cmd *c);
void	*xf_malloc(size_t n);
void	free_split(char **s);
void	ms_setup_signals_interactive(void);
void	ms_setup_signals_child(void);
void	ms_setup_signals_heredoc(void);
void	set_status(t_ms *ms, int code);
int		get_status(t_ms *ms);

#endif
