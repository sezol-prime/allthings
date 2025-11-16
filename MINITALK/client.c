/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:17:55 by sitao             #+#    #+#             */
/*   Updated: 2025/06/05 23:17:57 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	send_bit(int pid, unsigned char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		if (((ch >> i) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_ack_received == 0)
			pause();
		i--;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;
	char				*message;

	if (ac != 3)
	{
		ft_printf("Usage: ./client [PID] \"message\"\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 999999)
		return (1);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	message = av[2];
	while (*message != '\0')
		send_bit(pid, *message++);
	send_bit(pid, '\0');
	return (0);
}
