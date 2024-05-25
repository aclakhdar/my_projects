/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_hight_of_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:25:12 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/05 08:25:47 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	the_hight_of_map(char *line, int fd, t_map *cord)
{
	int	hight;

	hight = 1;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (strlen_of_line(line) != cord->long_map)
		{
			free(line);
			print_and_ex("The length of the map lines isn't the same");
		}
		free(line);
		hight++;
		line = get_next_line(fd);
	}
	free(line);
	cord->hight_map = hight;
}
