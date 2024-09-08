/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:44:11 by cliew             #+#    #+#             */
/*   Updated: 2024/09/08 23:14:41 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void	Contact::setFirst(str name) {
	this->first = name;
}

void	Contact::setLast(str last) {
	this->last = last;
}

void	Contact::setNick(str nick) {
	this->nick = nick;
}

void	Contact::setPhone(str phone) {
	this->phone = phone;
}

void	Contact::setSecret(str secret) {
	this->secret = secret;
}

str	Contact::getFirst() const {
	return this->first;
}

str Contact::getLast() const {
	return this->last;
}

str Contact::getNick() const {
	return this->nick;
}

str Contact::getPhone() const {
	return this->phone;
}

str	Contact::getSecret() const {
	return this->secret;
}