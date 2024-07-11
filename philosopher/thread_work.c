/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:54:04 by aclakhda          #+#    #+#             */
/*   Updated: 2024/07/08 18:34:38 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	philo_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num_of_philo)
	{
		if (check_dead(&philo[i], philo[0].time_to_die))
		{
			print_msg("deid", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_ate(t_philo *philo)
{
	int	i;
	int	finish_eating;

	finish_eating = 0;
	if (philo[0].num_time_eat == -1)
		return (0);
	i = 0;
	while (i < philo[0].num_of_philo)
	{
		pthread_mutex_lock(philo[0].meal_lock);
		if (philo[i].num_time_eat <= philo[0].meal_count)
			finish_eating++;
		pthread_mutex_unlock(philo[0].meal_lock);
		i++;
	}
	if (finish_eating == philo[0].num_of_philo)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*watching(void *elemnt)
{
	t_philo	*philo;

	philo = (t_philo *)elemnt;
	while (1)
		if (philo_dead(philo) || all_ate(philo))
			break ;
	return (NULL);
}

void	*routin(void *elemnt)
{
	t_philo	*philo;

	philo = (t_philo *)elemnt;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (NULL);
}
