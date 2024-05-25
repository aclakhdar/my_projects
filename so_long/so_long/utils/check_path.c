/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:21:22 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/04 01:33:53 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_path(char *path)
{
	size_t	i;
	int		j;

	i = strlen(path);
	j = ft_strncmp((path + i) - 4, ".ber", 4);
	if (j || path[i - 5] == '/')
		print_and_ex("invalide path to the map");
}
