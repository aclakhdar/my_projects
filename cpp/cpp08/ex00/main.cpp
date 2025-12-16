/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:07:38 by aclakhda          #+#    #+#             */
/*   Updated: 2025/08/05 17:11:01 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	try {
		std::cout << "Found in vector: " << *easyfind(vec, 5) << std::endl;
		std::cout << "Found in list: " << *easyfind(lst, 7) << std::endl;
		std::cout << "Found in deque: " << *easyfind(deq, 11) << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
