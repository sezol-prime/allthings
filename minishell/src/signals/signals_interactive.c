/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_interactive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:53:12 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 17:49:19 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

extern volatile sig_atomic_t	g_signal;

static void	sigint_interactive(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = SIGINT;
}

static void	sigquit_ignore(int sig)
{
	(void)sig;
}

void	ms_setup_signals_interactive(void)
{
	signal(SIGINT, sigint_interactive);
	signal(SIGQUIT, sigquit_ignore);
}

void	ms_setup_signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
