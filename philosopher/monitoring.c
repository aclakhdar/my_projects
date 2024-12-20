/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:44 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/19 14:14:59 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_full(t_philo *p, t_inst *in)
{
	int	i;

	i = 0;
	while (i < in->nphilo)
	{
		pthread_mutex_lock(p[i].meal_lock);
		if (p[i].full == 1)
		{
			in->full++;
			p[i].full = 0;
		}
		pthread_mutex_unlock(p[i].meal_lock);
		if (in->full == in->nphilo)
		{
			pthread_mutex_lock(&in->death_lock);
			in->death = 1;
			pthread_mutex_unlock(&in->death_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_delay(size_t tmp, t_inst *in)
{
	if (tmp >= in->tdie)
		return (1);
	return (0);
}

int	end_death(t_philo *p, t_inst *in) //check here
{
	int		i;
	size_t	tmp;

	i = 0;
	while (i < in->nphilo)
	{
		pthread_mutex_lock(p[i].meal_lock);
		tmp = get_current_time() - p[i].lastmeal;
		if (check_delay(tmp, in) && p[i].eating == 0)
		{
			pthread_mutex_unlock(p[i].meal_lock);
			pthread_mutex_lock(&in->death_lock);
			in->death = 1;
			pthread_mutex_unlock(&in->death_lock);
			return (p[i].id);
		}
		pthread_mutex_unlock(p[i].meal_lock);
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo	*p;
	t_inst	*in;
	int		p_death;

	p = (t_philo *)arg;
	in = p->in;
	p_death = 0;
	while (alive(p->in))
	{
		if (check_full(p, in))
			break ;
		p_death = end_death(p, in);
		if (p_death)
		{
			write_starved(p->in, p_death);
			break ;
		}
	}
	return (NULL);
}
