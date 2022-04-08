/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:50:41 by eseiv             #+#    #+#             */
/*   Updated: 2022/01/09 18:50:46 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (kill(pid, (c >> i & 1) + SIGUSR1) == -1)
		{
			exit(1);
		}
		usleep(800);
		i--;
	}
}

void	handler(int sig)
{
	(void)sig;
	write(1, "Server: successfully recieved\n", 30);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "Nombre d'argument insufisant\n", 29);
		return (0);
	}
	pid = ft_atoi(av[1]);
	s = av[2];
	signal(SIGUSR1, handler);
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char(0, pid);
}
