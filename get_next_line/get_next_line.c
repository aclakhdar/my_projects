/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:16:46 by aclakhda          #+#    #+#             */
/*   Updated: 2023/12/20 03:30:50 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	s_line(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*after_line(char *str)
{
	char	*buff;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
		return (free(str), NULL);
	buff = ft_substr(str, s_line(str) + 1, ft_strlen(str));
	free(str);
	str = buff;
	return (str);
}

char	*befor_line(char *str)
{
	char	*resurlt;

	resurlt = ft_substr(str, 0, s_line(str) + 1);
	return (resurlt);
}

char	*ft_join(int fd, char *str)
{
	ssize_t	i;
	char	*buff;

	i = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	while (i > 0 && !ft_strchr(buff, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(buff), free(str), NULL);
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE == 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	str = ft_join(fd, str);
	if (!str || str[0] == '\0')
		return (free(str), NULL);
	result = befor_line(str);
	str = after_line(str);
	return (result);
}
