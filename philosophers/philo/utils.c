/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:00:08 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 12:02:06 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		out;

	i = 0;
	sign = 1;
	out = 0;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' '
		|| (nptr[i] == '+' && (nptr[i + 1] > 47 && nptr[i + 1] < 58)))
		i++;
	if (nptr[i] == '-' && (nptr[i + 1] > 47 && nptr[i + 1] < 58))
	{
		sign = -1;
		i++;
	}
	while (nptr[i] != 0 && nptr[i] > 47 && nptr[i] < 58)
	{
		out = out * 10 + nptr[i] - '0';
		i++;
	}
	return (out * sign);
}

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}

void	print_state(char *s, t_philo *philo)
{
	long	timestamp;

	timestamp = get_time() - philo->input->start_time;
	pthread_mutex_lock(&philo->input->output_mutex);
	printf("%10ld  Philosopher  %d  %s.\n", timestamp, philo->id + 1, s);
	pthread_mutex_unlock(&philo->input->output_mutex);
}
