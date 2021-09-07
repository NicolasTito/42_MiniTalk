/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:01:19 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/07 17:39:07 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sigaction(int sig, siginfo_t *sinfo, void *context)
{
	static int		i = 0;
	static pid_t	cpid = 0;
	static char		c = 0;

	(void)context;
	if (!cpid)
		cpid = sinfo->si_pid;
	if (sig == SIGUSR1)
		c ^= 0x80 >> i;
	else if (sig == SIGUSR2)
		c |= 0x80 >> i;
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(cpid, SIGUSR2);
			cpid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(cpid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	s_sigaction.sa_sigaction = ft_sigaction;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
