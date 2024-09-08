/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:46:21 by cliew             #+#    #+#             */
/*   Updated: 2024/09/08 23:15:32 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "main.hpp"

class	PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	search_contact();
		
	private:
		const	int	max_contacts;
		int			current_number;
		int			contacts_number;
		Contact		array[8];

};

#endif