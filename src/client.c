/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:01:03 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/07 17:02:43 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sigaction(int sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
		++i;
	else
	{
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
}

static void	send_msg(int pid, char *msg)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (msg[++i])
	{
		while (++j < 8)
		{
			if (msg[i] & 0x80 >> j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	s_sigaction;

	if (ac != 3)
	{
		ft_putstr_fd("!!!ERROR!!!\nINAVALID ARGUMENT!\n", 1);
		return (0);
	}
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	s_sigaction.sa_handler = ft_sigaction;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	send_msg((int)ft_atoi(av[1]), av[2]);
	return (0);
}
