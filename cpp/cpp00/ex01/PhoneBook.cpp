/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:46:13 by cliew             #+#    #+#             */
/*   Updated: 2024/09/09 00:18:17 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook() : max_contacts(8), current_number(0), contacts_number(0) {
}

PhoneBook::~PhoneBook() {
}


void getNonEmptyInput(const std::string& prompt, std::string& input) {
    do {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Input cannot be blank. Please enter a valid input." << std::endl;
        }
    } while (input.empty());
}

void getValidIntegerInput(const std::string& prompt, std::string& input,int contacts_number) {
	int index = 0 ;
	int valid = 0;

	do {
        std::cout << prompt;
        std::getline(std::cin, input);
		index = atoi(input.c_str());
    if (input.empty()) {
            std::cout << "Please input a valid index!" << std::endl;
        }
	else if ((index == 0 && input[0] != '0') || (index+1> contacts_number || index < 0)) {
		std::cout << "Please enter a valid index !" << std::endl; 
	}

	else valid = 1;
    } while (valid==0);
}
void	PhoneBook::add_contact() {
	str	first;
	str	last;
	str	nick;
	str	phone;
	str	secret;

	if (this->current_number == 8)
		this->current_number = 0;
    getNonEmptyInput("Key in the first name: ", first);
    getNonEmptyInput("Key in the last name: ", last);
    getNonEmptyInput("Key in the nickname: ", nick);
    getNonEmptyInput("Key in the phone number: ", phone);
    getNonEmptyInput("Key in the darkest secret: ", secret);

	this->array[this->current_number].setFirst(first);
	this->array[this->current_number].setLast(last);
	this->array[this->current_number].setNick(nick);
	this->array[this->current_number].setPhone(phone);
	this->array[this->current_number].setSecret(secret);
	this->current_number++;
	if (contacts_number < 8)
		contacts_number++;
}

void	PhoneBook::search_contact() {
	int	i = 0;
	str	first;
	str	last;
	str	nick;
	str	phone;
	str	secret;
	str	search_index;
	int index;
	if (this->current_number == 0) {
		std::cout << "No contact avalaible !" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < contacts_number) {
		std::cout << std::setw(10) << i << "|";
		first = this->array[i].getFirst();
		last = this->array[i].getLast();
		nick = this->array[i].getNick();
		phone = this->array[i].getPhone();
		secret = this->array[i].getSecret();
		if (first.length() > 9)
			first = first.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << std::setw(10) << first << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << std::endl;
		i++;
	}

	getValidIntegerInput("Enter the index of contacts that you would like to check on: ", search_index,this->contacts_number);
	index = atoi(search_index.c_str());

	std::cout << "Name : " << this->array[index].getFirst() << std::endl;
	std::cout << "Lastname : " << this->array[index].getLast() << std::endl;
	std::cout << "Nickname : " << this->array[index].getNick() << std::endl;
	std::cout << "Phone number : " << this->array[index].getPhone() << std::endl;
	std::cout << "Darkest secret : " << this->array[index].getSecret() << std::endl;
}