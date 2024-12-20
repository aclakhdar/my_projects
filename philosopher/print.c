/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:00:50 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/19 14:14:35 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printtime(t_inst in)
{
	size_t	time_ms;

	time_ms = get_current_time() - in.start;
	printf("%lu ", time_ms);
}

void	write_starved(t_inst *in, int i)
{
	pthread_mutex_lock(&in->print);
	printtime(*in);
	printf("Philo %i died\n", i);
	pthread_mutex_unlock(&in->print);
}

void	write_message(char *str, t_philo *p)
{
	pthread_mutex_lock(&p->in->print);
	pthread_mutex_lock(p->meal_lock);
	if (alive(p->in) == 1)
	{
		printtime(*p->in);
		printf("Philo %d %s\n", p->id, str);
	}
	pthread_mutex_unlock(p->meal_lock);
	pthread_mutex_unlock(&p->in->print);
}
