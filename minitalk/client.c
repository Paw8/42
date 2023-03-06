/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:09:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/02 16:38:34 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_string(int pid, char *string)
{
	int				i;
	int				b;
	int				len;
	unsigned char	temp;

	len = ft_strlen(string);
	i = 0;
	while (i <= len)
	{
		b = 0;
		temp = string[i];
		while (b < 8)
		{
			usleep(10);
			if (((temp >> b) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			b++;
		}
		i++;
	}
}

static void	c_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Done\n", 5);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_sa	sa;
	int		pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (kill(pid, 0) == -1)
		{
			write(1, "Wrong PID\n", 10);
			return (0);
		}
		sa.sa_handler = &c_handler;
		sa.sa_flags = SA_NODEFER;
		sigemptyset(&sa.sa_mask);
		sigaddset(&sa.sa_mask, SIGUSR1);
		sigaddset(&sa.sa_mask, SIGUSR2);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_string(pid, argv[2]);
	}
	else
		write(1, "Invalid number of arguments!\n", 29);
	return (0);
}
