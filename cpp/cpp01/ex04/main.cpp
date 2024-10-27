/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:02:04 by cliew             #+#    #+#             */
/*   Updated: 2024/09/22 11:13:25 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define ARGS 0
#define INPUT 1
#define OUTPUT 2



void replaceStrings(std::ofstream &fileOut, const std::string &s1, const std::string &s2, const std::string &input) {
    size_t pos = input.find(s1);

    if (pos == std::string::npos) {
        fileOut << input;
        return;
    }

    fileOut << input.substr(0, pos) << s2;
    size_t toSkip = pos + s1.length();
    replaceStrings(fileOut, s1, s2, input.substr(toSkip));
}


int	main(int argc, char **argv)
{
	std::ifstream	fileIn;
	std::ofstream	fileOut;
	std::string		s1;
	std::string		s2;
	std::string		buff;
	std::string		file;
	std::string		fileReplace;

	if (argc != 4)
	{
		std::cerr << "There can only be 3 arguments,file s1 s2" << std::endl;
		return (1);
	}
	
	s1 = argv[2];
	s2 = argv[3];
	file = argv[1];
	fileIn.open(file.c_str());
	if (fileIn.good() == false)
	{
		std::cerr << "Input file not readable " << std::endl;
		return (1);
	}	

	
	fileReplace = file + ".replace";
	fileOut.open(fileReplace.c_str());
	if (fileOut.good() == false)
	{
		fileIn.close();
		std::cerr << "Output file not readable " << std::endl;
		return (1);
	}

	while (getline(fileIn, buff))
		replaceStrings(fileOut, s1, s2, buff + '\n');
	
	fileIn.close();
	fileOut.close();
	return (0);
}