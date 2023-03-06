/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:58:45 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 12:00:59 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input		input;
	t_philo		*philos;
	pthread_t	*threads;

	if (validate_input(argc, argv, &input))
		return (1);
	philos = malloc(input.number_philos * sizeof(t_philo));
	if (!philos)
	{
		destroy_mutex(&input);
		free_mutex(&input);
		return (printf("Memory allocation for philos has failed.\n"));
	}
	threads = malloc(input.number_philos * sizeof(pthread_t));
	if (!threads)
	{
		destroy_mutex(&input);
		free(philos);
		free_mutex(&input);
		return (printf("Memory allocation for threads has failed.\n"));
	}
	if (init_philos(&input, philos, threads))
		return (1);
	exit_philo(threads, philos, &input);
	return (0);
}

int	validate_input(int argc, char *argv[], t_input *input)
{
	if (argc < 5 || argc > 6)
		return (printf("Number of arguments is invalid\n"));
	if (validate_args(argc, argv))
		return (1);
	input->number_philos = ft_atoi(argv[1]);
	if (input->number_philos < 1)
		return (printf("Number of Philos needs to be at least 1\n"));
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	input->died = 0;
	if (argc == 6)
		input->number_eat = ft_atoi(argv[5]);
	else
		input->number_eat = -1;
	if (input->number_eat == 0)
		return (printf("Eating amount should not be 0\n"));
	if (init_forks(input))
		return (1);
	if (init_mutex(input))
		return (1);
	return (0);
}

int	validate_args(int argc, char *argv[])
{
	int	i;

	argc--;
	while (argc > 0)
	{
		i = 0;
		if (argv[argc][i] == '-')
			return (printf("Arguments can't be negative.\n"));
		if (argv[argc][i] == '+')
			i++;
		while (argv[argc][i])
		{
			if (argv[argc][i] < '0' || argv[argc][i] > '9')
				return (printf("Wrong argument format.\n"));
			i++;
		}
		argc--;
	}
	return (0);
}
