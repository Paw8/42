/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:57:45 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 16:50:10 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_input *input, t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	input->start_time = get_time();
	while (i < input->number_philos)
	{
		philos[i].input = input;
		philos[i].id = i;
		philos[i].right_fork = i;
		philos[i].last_eaten = input->start_time;
		if (i == 0)
			philos[i].left_fork = input->number_philos - 1;
		else
			philos[i].left_fork = i - 1;
		if (pthread_create(&threads[i], NULL, &start_routine, &philos[i]))
			return (malloc_thread_failed(threads, philos, input, i));
		i++;
	}
	return (0);
}

int	malloc_thread_failed(pthread_t *threads, t_philo *philos, \
t_input *input, int i)
{
	while (i > 0)
	{
		pthread_join(threads[i], NULL);
		i--;
	}
	destroy_mutex(input);
	free(input->forks_mutex);
	free(input->blockneighbor);
	free(input->forks);
	free(philos);
	free(threads);
	return (printf("Threads could not be created.\n"));
}

void	*start_routine(void *v_philo)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *) v_philo;
	if (philo->id % 2 == 1)
		usleep(1000);
	i = 0;
	while (i < philo->input->number_eat || philo->input->number_eat == -1)
	{
		if (death_check(philo))
			break ;
		if (take_forks(philo))
			break ;
		if (eat_sleep_think(philo))
			break ;
		if (philo->input->number_eat != -1)
			i++;
	}
	return (0);
}

int	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->death_mutex);
	if (philo->input->died)
	{
		pthread_mutex_unlock(&philo->input->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->input->death_mutex);
	if ((get_time() - philo->last_eaten) > philo->input->time_die)
	{
		pthread_mutex_lock(&philo->input->death_mutex);
		philo->input->died = 1;
		pthread_mutex_unlock(&philo->input->death_mutex);
		print_state("has died", philo);
		return (1);
	}
	return (0);
}

void	exit_philo(pthread_t *threads, t_philo *philos, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->number_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	destroy_mutex(input);
	free(input->forks_mutex);
	free(input->blockneighbor);
	free(input->forks);
	free(philos);
	free(threads);
}
