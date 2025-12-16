/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:22:27 by aclakhda          #+#    #+#             */
/*   Updated: 2025/08/07 18:26:27 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	try {
		// Create a Span with room for 10,000 numbers
		Span sp(10000);

		// Fill the Span with random numbers
		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// // Now test adding a range
		std::vector<int> moreNumbers;
		for (int i = 0; i < 1000; ++i) {
			moreNumbers.push_back(std::rand());
		}

		Span sp2(2000);
		// sp2.addNumber(moreNumbers.begin(), moreNumbers.end());

		// std::cout << "sp2 Shortest span: " << sp2.shortestSpan() << std::endl;
		// std::cout << "sp2 Longest span: " << sp2.longestSpan() << std::endl;

		// Testing errors: adding too many numbers
		// try {
		// 	for (int i = 0; i < 3000; ++i) {
		// 		sp2.addNumber(std::rand());
		// 	}
		// } catch (const std::exception& e) {
		// 	std::cout << "Caught expected exception: " << e.what() << std::endl;
		// }

	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
