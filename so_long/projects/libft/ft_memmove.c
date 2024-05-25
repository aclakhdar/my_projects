/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:50:44 by aclakhda          #+#    #+#             */
/*   Updated: 2023/11/24 20:04:35 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*string;
	unsigned char	*string2;

	string = (unsigned char *)dest;
	string2 = (unsigned char *)src;
	if (!string && !string2)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			string[n - 1] = string2[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
