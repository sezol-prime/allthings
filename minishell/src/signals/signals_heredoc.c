/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:52:48 by mipang            #+#    #+#             */
/*   Updated: 2025/11/06 17:50:27 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

extern volatile sig_atomic_t	g_signal;

static void	sigint_heredoc(int sig)
{
	(void)sig;
	g_signal = SIGINT;
	write(1, "\n", 1);
}

void	ms_setup_signals_heredoc(void)
{
	signal(SIGINT, sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
