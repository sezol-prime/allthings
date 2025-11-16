/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:18:02 by sitao             #+#    #+#             */
/*   Updated: 2025/06/05 23:18:08 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;
	unsigned char			output;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			output = '\n';
			write(1, &output, 1);
		}
		else
		{
			output = c;
			write(1, &output, 1);
		}
		c = 0;
		bit = 0;
	}
	usleep(42);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
