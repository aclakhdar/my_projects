/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:10:49 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/18 14:32:35 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alive(t_inst *in)
{
	pthread_mutex_lock(&in->death_lock);
	if (in->death == 1)
		return (pthread_mutex_unlock(&in->death_lock), 0);
	pthread_mutex_unlock(&in->death_lock);
	return (1);
}

void	update_meal(t_philo *p)
{
	pthread_mutex_lock(p->meal_lock);
	p->lastmeal = get_current_time();
	p->eating = 1;
	p->in->counter[p->id]++;
	pthread_mutex_unlock(p->meal_lock);
}

void	ft_usleep(size_t msec)
{
	size_t	start;
	int		i;

	i = 0;
	if (msec == 0)
		return ;
	start = get_current_time();
	while (get_current_time() - start < msec)
		i++;
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->in->nphilo == 1)
	{
		pthread_mutex_lock(p->lfork);
		write_message("has taken his left fork", p);
		ft_usleep(p->in->tdie);
		return (pthread_mutex_unlock(p->lfork), NULL);
	}
	if (p->id % 2 == 0)
		ft_usleep(p->in->THINK_TIME);
	while (alive(p->in))
	{
		if (eat(p))
			break ;
		nap(p);
		think(p);
	}
	return (NULL);
}
