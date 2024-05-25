/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:15:03 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 20:39:10 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_checker(char *path)
{
	t_map	cord;
	int		fd;
	char	*line;

	check_path(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_and_ex("the file of the map didnt open!");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		print_and_ex("the map is empty!");
	}
	cord.long_map = strlen_of_line(line);
	the_hight_of_map(line, fd, &cord);
	if (cord.long_map > 41 || cord.hight_img > 24)
	{
		close(fd);
		print_and_ex("can u make the map smaller for smother experiance <:");
	}
	close(fd);
	map(path, &cord);
}
