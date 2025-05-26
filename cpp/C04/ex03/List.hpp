/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:03:26 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 14:58:09 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "header.hpp"
#include <iostream>
#include <string>

struct list
{
	AMateria *m;
	struct list *next;
};

void free_list(list *head);
list *deep_copy(list *head);
void push_last(list **head, AMateria *m);
void print_l(list *head);

