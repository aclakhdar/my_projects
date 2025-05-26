/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:25:34 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/22 13:49:33 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a(2);
	Fixed const b(1);
	// Fixed d(10);

	std::cout << a << std::endl;
	// std::cout << b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
