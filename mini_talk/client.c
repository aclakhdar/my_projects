/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:57:31 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/02/22 16:13:58 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	chartobyte(int pid, char *str)
{
	int		i;
	int		j;
	int		signal;

	i = 0;
	while (str[i])
	{
		j = 7;
		if (ft_isascii(str[i]))
		{
			while (j >= 0)
			{
				signal = SIGUSR2;
				if (str[i] & (1 << j))
					signal = SIGUSR1;
				if (kill(pid, signal) == -1)
					return (0);
				j--;
				usleep(200);
			}
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("something wrong with argument pls retry again!!");
		return (1);
	}
	if (ac == 3)
	{
		if (!ft_strlen(av[2]))
		{
			ft_printf("cant send an empty string!");
			return (1);
		}
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			ft_printf("pid is not valid.\n");
		else if (kill(pid, 0) == -1)
			ft_printf("Process not found.\n");
		else if (!chartobyte(pid, av[2]))
			ft_printf("Failed to send signal.\n");
	}
	return (0);
}
