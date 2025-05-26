/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:58:41 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 15:11:09 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include "AMateria.hpp"

void free_list(list *head)
{
	list *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp->m;
		delete tmp;
	}
}

list *deep_copy(list *head)
{
	list *new_head = NULL;
	list *new_node = NULL;
	list *tmp = head;

	while (tmp)
	{
		new_node = new list;
		new_node->m = tmp->m->clone();
		new_node->next = new_head;
		new_head = new_node;
		tmp = tmp->next;
	}
	return (new_head);
}

void push_last(list **head, AMateria *m)
{
	list *new_node = new list;
	list *tmp = *head;

	new_node->m = m;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		std::cout << "New node created with materia: " << m->getType() << std::endl;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void print_l(list *head)
{
	list *tmp = head;
	int i = 0;
	while (tmp)
	{
		std::cout << i++ << ": ";
		std::cout << tmp->m->getType() << std::endl;
		tmp = tmp->next;
	}
}
