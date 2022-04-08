/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:31:27 by eseiv             #+#    #+#             */
/*   Updated: 2022/01/09 18:56:58 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	reset(int pid, char *c, int *n)
{
	*n = 0;
	*c = 0;
	g_pid = pid;
}

void	f(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	n;

	(void) context;
	if (g_pid != info->si_pid)
		reset(info->si_pid, &c, &n);
	c = c << 1 | (sig - 30);
	n++;
	if (n == 8)
	{
		write(1, &c, 1);
		n = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &f;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
