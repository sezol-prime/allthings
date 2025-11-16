/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:11:25 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 17:48:17 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

static void	preload_env(t_ms *ms, char **envp)
{
	ms->env = env_from(envp);
	ms->last_status = 0;
	ms->heredoc_sigint = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_ms		ms;
	extern int	rl_catch_signals;
	extern int	rl_catch_sigwinch;

	(void)argv;
	if (argc != 1)
		return (1);
	preload_env(&ms, envp);
	rl_catch_signals = 0;
	rl_catch_sigwinch = 0;
	ms_setup_signals_interactive();
	return (ms_loop(&ms));
}
