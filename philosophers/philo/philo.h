/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:41:49 by pcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 16:49:29 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_input {
	int				number_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_eat;
	int				*forks;
	int				died;
	long			start_time;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*blockneighbor;
	pthread_mutex_t	output_mutex;
	pthread_mutex_t	death_mutex;
}t_input;

typedef struct s_philo {
	int		id;
	int		left_fork;
	int		right_fork;
	long	last_eaten;
	t_input	*input;
}t_philo;

int		validate_input(int argc, char *argv[], t_input *input);
int		validate_args(int argc, char *argv[]);
int		init_forks(t_input *input);
int		init_mutex(t_input *input);
int		destroy_mutex(t_input *input);
int		mutex_failed(t_input *input);
void	free_mutex(t_input *input);
int		init_philos(t_input *input, t_philo *philos, pthread_t *threads);
int		malloc_thread_failed(pthread_t *threads, t_philo *philos, \
		t_input *input, int i);
long	get_time(void);
void	*start_routine(void *v_philo);
int		death_check(t_philo *philo);
int		take_forks(t_philo *philo);
int		wait_for_fork(t_philo *philo);
int		eat_sleep_think(t_philo *philo);
int		idle(long wait_until, t_philo *philo, int eating);
void	exit_philo(pthread_t *threads, t_philo *philos, t_input *input);
void	print_state(char *s, t_philo *philo);
int		ft_atoi(const char *nptr);

#endif
