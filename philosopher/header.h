/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:58:26 by aclakhda          #+#    #+#             */
/*   Updated: 2024/07/08 00:10:49 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				num_of_philo;
	int				meal_count;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating;
	int				num_time_eat;
	size_t			time_to_die;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
}				t_philo;

typedef struct s_mutex
{
	int				dead_flags;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philo;
}					t_mutex;

int		ft_atoi(const char *str);
void	init_program(t_mutex *init, t_philo *philo);
void	init_forks(pthread_mutex_t *fork, int num_philos);
size_t	get_current_time(void);
void	init_philo(t_philo *philo, t_mutex *init, pthread_mutex_t *fork,
			char **av);
void	destroy_all(char *str, t_mutex *init, pthread_mutex_t *fork);
void	creat_threads(t_mutex *init, pthread_mutex_t *fork);
void	*watching(void *elemnt);
void	*routin(void *elemnt);
void	print_msg(char *str, t_philo *philo, int id);
int		dead_loop(t_philo *philo);
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);

#endif
