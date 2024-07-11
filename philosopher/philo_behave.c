/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:20:04 by aclakhda          #+#    #+#             */
/*   Updated: 2024/07/08 00:06:55 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken right fork", philo, philo->id);
	if (philo->num_of_philo == 1)
	{
		usleep(philo->time_to_die * 1000);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken left fork", philo, philo->id);
	philo->eating = 1;
	print_msg("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->time_to_eat * 1000);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	dream(t_philo *philo)
{
	print_msg("is sleeping", philo, philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	print_msg("is thinking", philo, philo->id);
}
