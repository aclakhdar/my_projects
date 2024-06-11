/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:08:34 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 15:21:46 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **a, t_node **b)
{
	ra(a, 2);
	ra(b, 2);
	write(1, "rr\n", 3);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 2);
	rra(b, 2);
	write(1, "rrr\n", 4);
}

void	ss(t_node **a, t_node **b)
{
	sa(a, 2);
	sa(b, 2);
	write(1, "ss\n", 3);
}
