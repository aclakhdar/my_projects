/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:15:27 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/17 17:44:38 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed;
		static const int	Bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed &operator=(const Fixed &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
