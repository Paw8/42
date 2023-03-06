/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:57:52 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/18 12:06:56 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	while (death_check(philo) == 0)
	{
		pthread_mutex_lock(&philo->input->blockneighbor[philo->left_fork]);
		if (philo->input->forks[philo->left_fork] == 0)
		{
			philo->input->forks[philo->left_fork] = 1;
			pthread_mutex_unlock(&philo->input->blockneighbor \
			[philo->left_fork]);
			pthread_mutex_lock(&philo->input->forks_mutex[philo->left_fork]);
			print_state("has taken left fork", philo);
			if (wait_for_fork(philo))
				return (1);
			else
				return (0);
		}
		else
			pthread_mutex_unlock(&philo->input->blockneighbor \
			[philo->left_fork]);
		usleep(1000);
	}
	return (1);
}

int	wait_for_fork(t_philo *philo)
{
	while (1)
	{
		if (death_check(philo))
		{
			pthread_mutex_unlock(&philo->input->forks_mutex[philo->left_fork]);
			return (1);
		}
		pthread_mutex_lock(&philo->input->blockneighbor[philo->right_fork]);
		if (philo->input->forks[philo->right_fork] == 0)
		{
			philo->input->forks[philo->right_fork] = 1;
			pthread_mutex_unlock(&philo->input->blockneighbor \
			[philo->right_fork]);
			pthread_mutex_lock(&philo->input->forks_mutex[philo->right_fork]);
			print_state("has taken right fork", philo);
			return (0);
		}
		else
			pthread_mutex_unlock(&philo->input->blockneighbor \
			[philo->right_fork]);
		usleep(1000);
	}
}

int	eat_sleep_think(t_philo *philo)
{
	if (death_check(philo))
		return (1);
	print_state("is eating", philo);
	philo->last_eaten = get_time();
	if (idle(philo->last_eaten + philo->input->time_eat, philo, 1))
		return (1);
	pthread_mutex_lock(&philo->input->blockneighbor[philo->left_fork]);
	philo->input->forks[philo->left_fork] = 0;
	pthread_mutex_unlock(&philo->input->blockneighbor[philo->left_fork]);
	pthread_mutex_unlock(&philo->input->forks_mutex[philo->left_fork]);
	pthread_mutex_lock(&philo->input->blockneighbor[philo->right_fork]);
	philo->input->forks[philo->right_fork] = 0;
	pthread_mutex_unlock(&philo->input->blockneighbor[philo->right_fork]);
	pthread_mutex_unlock(&philo->input->forks_mutex[philo->right_fork]);
	print_state("is sleeping", philo);
	if (idle(get_time() + philo->input->time_sleep, philo, 0))
		return (1);
	print_state("is thinking", philo);
	return (0);
}

int	idle(long wait_until, t_philo *philo, int eating)
{
	while (wait_until > get_time())
	{
		if (death_check(philo))
		{
			if (eating)
			{
				pthread_mutex_unlock(&philo->input->forks_mutex \
				[philo->left_fork]);
				pthread_mutex_unlock(&philo->input->forks_mutex \
				[philo->right_fork]);
			}
			return (1);
		}
		usleep(1000);
	}
	return (0);
}
