/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:51:12 by cliew             #+#    #+#             */
/*   Updated: 2024/10/05 08:11:07 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_numFrac = 8;

	public:
		Fixed(void);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		Fixed(const int n);
		Fixed(const float n);
		float toFloat( void ) const;
		int toInt( void ) const;
		
};
std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);


#endif