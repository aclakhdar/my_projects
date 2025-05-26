/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:23:59 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/18 15:27:40 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*ptr_str = &str;
	std::string &ref_str = str;
	//memory address
	std::cout << &ref_str << "\n";
	std::cout << &str << "\n";
	std::cout << &ptr_str << "\n";
	//value
	std::cout << ref_str << "\n";
	std::cout << str << "\n";
	std::cout << *ptr_str << "\n";
}
