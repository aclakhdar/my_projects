/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:05:34 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/20 22:21:23 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strlenght(char *src)
{
	int	l;

	l = 0;
	while (*src != '\0')
	{
		src++;
		l++;
	}
	return (l);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				n;

	i = 0;
	n = strlenght(src);
	if (size < 1)
		return (n);
	while (*src != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (n);
}
