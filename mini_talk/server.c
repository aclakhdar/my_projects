/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:02:43 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/02/22 16:14:13 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static char	c;
	static int	i;

	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("%d\n", pid);
	while (1)
		pause();
}
