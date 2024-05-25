/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:51:37 by aclakhda          #+#    #+#             */
/*   Updated: 2023/10/04 18:24:25 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_index(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size <= 1)
		return (1);
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_sign(char *c, int *i)
{
	int	sign;

	sign = 1;
	while (c[*i] == '-' || c[*i] == '+')
	{
		if (c[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	size;
	int	index;
	int	sign;
	int	number;

	size = ft_strlen(base);
	i = 0;
	number = 0;
	if (ft_check(base, size) == 1)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = ft_sign(str, &i);
	while (str[i])
	{
		index = ft_index(str[i], base);
		if (index == -1)
			return (number * sign);
		number = number * size + index;
		i++;
	}
	return (number * sign);
}
