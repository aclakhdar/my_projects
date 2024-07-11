/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:00:11 by aclakhda          #+#    #+#             */
/*   Updated: 2024/07/06 17:53:43 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_av_content(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_and_ex(char *str, int i)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(i);
}

void	check_av(char **av)
{
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) <= 0
		|| check_av_content(av[1]) == 1)
		print_and_ex("invalide philisopher number", 1);
	if (ft_atoi(av[2]) <= 0 || check_av_content(av[2]))
		print_and_ex("invalide time to die", 1);
	if (ft_atoi(av[3]) <= 0 || check_av_content(av[3]))
		print_and_ex("invalide time to eat", 1);
	if (ft_atoi(av[4]) <= 0 || check_av_content(av[4]))
		print_and_ex("invalide time to sleep", 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || check_av_content(av[5])))
		print_and_ex("invalide number of meal must eash philo eat!", 1);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	fork[200];
	t_philo			philo[200];
	t_mutex			init;

	if (ac != 5 && ac != 6)
		print_and_ex("argumant error", 1);
	check_av(av);
	init_program(&init, philo);
	init_forks(fork, ft_atoi(av[1]));
	init_philo(philo, &init, fork, av);
	creat_threads(&init, fork);
	destroy_all(NULL, &init, fork);
}
