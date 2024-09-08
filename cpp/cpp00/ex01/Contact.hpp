/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 05:42:27 by cliew             #+#    #+#             */
/*   Updated: 2024/09/08 23:23:26 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
	public:
		Contact();
		~Contact();

		void	setFirst(str name);
		void	setLast(str last);
		void	setNick(str nick);
		void	setPhone(str phone);
		void	setSecret(str secret);
		str		getFirst() const;
		str		getLast() const;
		str		getNick() const;
		str		getPhone() const;
		str		getSecret() const;

	private:
		str	first;
		str	last;
		str	nick;
		str	phone;
		str	secret;

};
#endif