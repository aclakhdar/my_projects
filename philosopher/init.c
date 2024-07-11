/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:44:55 by aclakhda          #+#    #+#             */
/*   Updated: 2024/07/08 00:09:43 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_program(t_mutex *init, t_philo *philo)
{
	init->philo = philo;
	init->dead_flags = 0;
	pthread_mutex_init(&init->meal_lock, NULL);
	pthread_mutex_init(&init->dead_lock, NULL);
	pthread_mutex_init(&init->write_lock, NULL);
}

void	init_forks(pthread_mutex_t *fork, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}

void	init_p(t_philo *philo, char **av)
{
	philo->time_to_die = (size_t)ft_atoi(av[2]);
	philo->num_of_philo = ft_atoi(av[1]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->num_time_eat = ft_atoi(av[5]);
	else
		philo->num_time_eat = -1;
}

void	init_philo(t_philo *philo, t_mutex *init, pthread_mutex_t *fork,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		init_p(&philo[i], av);
		philo[i].l_fork = &fork[i];
		philo[i].eating = 0;
		philo[i].meal_count = 0;
		philo[i].last_meal = get_current_time();
		philo[i].start_time = get_current_time();
		philo[i].meal_lock = &init->meal_lock;
		philo[i].dead_lock = &init->dead_lock;
		philo[i].write_lock = &init->write_lock;
		philo[i].dead = &init->dead_flags;
		if (i == 0)
			philo[i].r_fork = &fork[philo[i].num_of_philo - 1];
		else
			philo[i].r_fork = &fork[i - 1];
		i++;
	}
}

void	creat_threads(t_mutex *init, pthread_mutex_t *fork)
{
	int			i;
	pthread_t	spectator;

	i = 0;
	if (pthread_create(&spectator, NULL, &watching, init->philo) != 0)
		destroy_all("thread creating error", init, fork);
	while (i < init->philo[0].num_of_philo)
	{
		if (pthread_create(&init->philo[i].thread, NULL, &routin,
				&init->philo[i]) != 0)
			destroy_all("thread creating error", init, fork);
		i++;
	}
	if (pthread_join(spectator, NULL) != 0)
		destroy_all("thread_join failed", init, fork);
	i = 0;
	while (i < init->philo[0].num_of_philo)
	{
		if (pthread_join(init->philo[i].thread, NULL) != 0)
			destroy_all("thread_join failed", init, fork);
		i++;
	}
}
