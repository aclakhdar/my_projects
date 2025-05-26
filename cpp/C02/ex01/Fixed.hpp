/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:15:27 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/26 15:10:36 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(const Fixed &copy);
		~Fixed();
		void operator=(const Fixed &copy);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &value);

#endif
