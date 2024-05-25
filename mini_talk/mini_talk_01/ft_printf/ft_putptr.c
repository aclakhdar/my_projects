/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:37:54 by aclakhda          #+#    #+#             */
/*   Updated: 2023/12/08 17:42:30 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	if (!ptr)
	{
		count += write (1, "0", 1);
		return (count);
	}
	count += ft_printhex(ptr, 0);
	return (count);
}
