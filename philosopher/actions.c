/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:57:33 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/17 21:44:53 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	nap(t_philo *p)
{
	write_message("is sleeping", p);
	ft_usleep(p->in->tsleep);
}

void	think(t_philo *p)
{
	write_message("is thinking", p);
	ft_usleep(5); // u need sleep when t_sleep t_eat less than 80 or 100 ms
}

void	fork_lock(t_philo *p)
{
	if (p->lfork < p->rfork)
	{
		pthread_mutex_lock(p->lfork);
		write_message("has taken left fork", p);
		pthread_mutex_lock(p->rfork);
		write_message("has taken right fork", p);
	}
	else
	{
		pthread_mutex_lock(p->rfork);
		write_message("has taken right fork", p);
		pthread_mutex_lock(p->lfork);
		write_message("has taken left fork", p);
	}
}

int	eat(t_philo *p)
{
	fork_lock(p);
	// pthread_mutex_lock(p->lfork);
	// write_message("has taken left fork", p);
	// pthread_mutex_lock(p->rfork);
	// write_message("has taken right fork", p);
	update_meal(p);
	write_message("started eating", p);
	ft_usleep(p->in->teat);
	pthread_mutex_lock(p->meal_lock);
	p->eating = 0;
	pthread_mutex_unlock(p->meal_lock);
	pthread_mutex_unlock(p->rfork);
	pthread_mutex_unlock(p->lfork);
	if (p->in->counter[p->id] == p->in->nmeals)
	{
		pthread_mutex_lock(p->meal_lock);
		p->full = 1;
		return (pthread_mutex_unlock(p->meal_lock), 1);
	}
	return (0);
}
