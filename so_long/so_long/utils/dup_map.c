/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:58:08 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:16:21 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lines_counter(char *path)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_and_ex("error happend when trying to open the file");
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		counter++;
	}
	close(fd);
	return (counter);
}

char	**dup_map(char *path)
{
	char	**arr;
	int		i;
	char	*line;
	int		fd;
	int		line_map;

	i = 0;
	line_map = lines_counter(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_and_ex("error happend when trying to open the file");
	arr = malloc((line_map + 1) * sizeof(char *));
	if (!arr)
		print_and_ex("allocation failed in dup_map function");
	line = get_next_line(fd);
	while (line)
	{
		arr[i] = line;
		i++;
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	free(line);
	close(fd);
	return (arr);
}
