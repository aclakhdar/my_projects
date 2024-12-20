/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:34 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/11 20:14:46 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo *p, t_inst *in)
{
	int	i;

	i = 0;
	if (pthread_join(in->monitor, NULL))
	{
		set_error(in);
		return (print_error("The threads joining process has failed\n"));
	}
	while (i < in->nphilo)
	{
		if (pthread_join(p[i].th, NULL))
		{
			set_error(in);
			return (print_error("The threads joining process has failed\n"));
		}
		i++;
	}
	return (1);
}

int	destroy_mutex(t_inst *in, t_fork *m, t_fork *f)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&in->death_lock))
		return (print_error("Mutex destruction failure\n"));
	if (pthread_mutex_destroy(&in->print))
		return (print_error("Mutex destruction failure\n"));
	while (i < in->nphilo)
	{
		if (pthread_mutex_destroy(&m[i]))
			return (print_error("Mutex destruction failure\n"));
		if (pthread_mutex_destroy(&f[i]))
			return (print_error("Mutex destruction failure\n"));
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fork	f[200];
	t_fork	m[200];
	t_philo	p[200];
	t_inst	inst;

	if (!check_argument(ac, av))
		return (1);
	fill_instructions(&inst, ac, av);
	if (!check_instructions(&inst, ac))
		return (1);
	if (!init_mutex(f, m, &inst))
		return (1);
	fill_philos(p, m, &inst, f);
	if (!init_threads(p, &inst))
		return (destroy_mutex(&inst, m, f), 1);
	if (!join_threads(p, &inst))
		return (destroy_mutex(&inst, m, f), 1);
	destroy_mutex(&inst, m, f);
}
