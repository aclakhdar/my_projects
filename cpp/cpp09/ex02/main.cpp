/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:16:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/09/06 14:17:10 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	try {
		if (ac < 2)
			throw std::invalid_argument("Error: No arguments provided.");
		if (ac == 2)
			throw std::invalid_argument("Error: Too few numbers to sort");
		PmergeMe pm;
		pm.parse(ac, av);
		pm.sort();
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Error: Unknown error occurred." << std::endl;
		return 1;
	}
}
