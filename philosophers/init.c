/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:57:33 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 16:54:08 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_input *input)
{
	int	i;

	input->forks = malloc(input->number_philos * sizeof(int));
	if (!(input->forks))
		return (printf("Malloc forks failed.\n"));
	i = 0;
	while (i < input->number_philos)
	{
		input->forks[i] = 0;
		i++;
	}
	return (0);
}

int	init_mutex(t_input *input)
{
	int	i;

	input->forks_mutex = malloc(input->number_philos * sizeof(pthread_mutex_t));
	input->blockneighbor = \
	malloc(input->number_philos * sizeof(pthread_mutex_t));
	if (!input->forks_mutex || !input->blockneighbor)
	{
		free(input->forks);
		return (printf("Allocation for the forks_mutex failed.\n"));
	}
	i = input->number_philos;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(input->forks_mutex[i]), NULL))
			return (mutex_failed(input));
		if (pthread_mutex_init(&(input->blockneighbor[i]), NULL))
			return (mutex_failed(input));
	}
	if (pthread_mutex_init(&(input->output_mutex), NULL))
		return (mutex_failed(input));
	if (pthread_mutex_init(&(input->death_mutex), NULL))
		return (mutex_failed(input));
	return (0);
}

int	destroy_mutex(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->number_philos)
	{
		pthread_mutex_destroy(&input->forks_mutex[i]);
		pthread_mutex_destroy(&input->blockneighbor[i]);
		i++;
	}
	pthread_mutex_destroy(&input->output_mutex);
	pthread_mutex_destroy(&input->death_mutex);
	return (0);
}

int	mutex_failed(t_input *input)
{
	free(input->forks);
	free(input->forks_mutex);
	free(input->blockneighbor);
	return (printf("Mutex failed.\n"));
}

void	free_mutex(t_input *input)
{
	free(input->forks);
	free(input->forks_mutex);
	free(input->blockneighbor);
}
