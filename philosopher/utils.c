/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:11:47 by aclakhda          #+#    #+#             */
/*   Updated: 2024/07/09 16:22:23 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_pos;
	int	number;

	i = 0;
	is_pos = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_pos *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	return (number * is_pos);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(1, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	destroy_all(char *str, t_mutex *init, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	pthread_mutex_destroy(&init->dead_lock);
	pthread_mutex_destroy(&init->meal_lock);
	pthread_mutex_destroy(&init->write_lock);
	while (i < init->philo[0].num_of_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}

int	dead_loop(t_philo *philo)
{
	//printf("hello ana hna :D\n");
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	print_msg(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
