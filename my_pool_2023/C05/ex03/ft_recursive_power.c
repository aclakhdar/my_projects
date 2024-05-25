/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:40:28 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/26 18:49:59 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	resu;

	resu = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (resu * ft_recursive_power(resu, power - 1));
}
