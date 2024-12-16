#include "ScalarConverter.hpp"
void	printSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

// void	convertChar(const std::string& str, size_t& len)
// {
// 	char	c = 0;

// 	if (len == 1)
// 		c = str[0];
// 	else
// 		c = str[1];
// 	std::cout << "char: ";
// 	if (isprint(c))
// 	{
// 		std::cout << "'" << c << "'" << std::endl;
// 		std::cout << "int: " << static_cast<int>(c) << std::endl;
// 		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
// 		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
// 	}
// 	else
// 		std::cout << "Non displayable" << std::endl;
// }

// void	convertInt(const std::string& str)
// {
// 	long	l = std::atol(str.c_str());

// 	std::cout << "char: ";
// 	if (l < 0 || l > 127)
// 		std::cout << "impossible" << std::endl;
// 	else
// 	{
// 		if (isprint(l))
// 			std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
// 		else
// 			std::cout << "Non displayable" << std::endl;
// 	}
// 	std::cout << "int: ";
// 	if (l < MIN_INT || l > MAX_INT)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout	<< static_cast<int>(l) << std::endl;
// 	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
// }

// void	convertFloat(const std::string& str)
// {
// 	float	f = std::atof(str.c_str());
// 	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

// 	std::cout << "char: ";
// 	if (f < 0 || f > 127)
// 		std::cout << "impossible" << std::endl;
// 	else
// 	{
// 		if (isprint(f))
// 			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
// 		else 
// 			std::cout << "Non displayable" << std::endl;
// 	}
// 	std::cout << "int: ";
// 	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << static_cast<int>(f) << std::endl;
// 	std::cout << "float: ";
// 	if (f < MIN_FLOAT || f > MAX_FLOAT)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << f << (tolerance ? ".0f" : "f") << std::endl;
// 	std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
// }

// void	convertDouble(const std::string& str)
// {
// 	double		d = std::atof(str.c_str());
// 	bool		tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

// 	std::cout << "char: ";
// 	if (d < 0 || d > 127)
// 		std::cout << "impossible" << std::endl;
// 	else
// 	{
// 		if (isprint(d))
// 			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
// 		else 
// 			std::cout << "Non displayable" << std::endl;
// 	}
// 	std::cout << "int: ";
// 	if (d < MIN_INT || d > MAX_INT)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << static_cast<int>(d) << std::endl;
// 	std::cout << "float: ";
// 	if (d < MIN_FLOAT || d > MAX_FLOAT)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
// 	std::cout << "double: ";
// 	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << d << std::endl;
// }

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>

// Helper function to print the char conversion
void printChar(double d)
{
    if (d < 0 || d > 127) 
        std::cout << "impossible" << std::endl;
    else
    {
        if (isprint(static_cast<int>(d))) 
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else 
            std::cout << "Non displayable" << std::endl;
    }
}

// Helper function to print the int conversion
void printInt(double d)
{
    if (d < MIN_INT || d > MAX_INT) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

// Helper function to print the float conversion
void printFloat(double d, bool tolerance)
{
    if (d < MIN_FLOAT || d > MAX_FLOAT) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
}

// Helper function to print the double conversion
void printDouble(double d)
{
    if (d < MIN_DOUBLE || d > MAX_DOUBLE) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << d << std::endl;
}

// Convert char to all types
void convertChar(const std::string& str, size_t& len)
{
    char c = (len == 1) ? str[0] : str[1];
    
    std::cout << "char: ";
    printChar(c);
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// Convert int to all types
void convertInt(const std::string& str)
{
    long l = std::atol(str.c_str());
    
    std::cout << "char: ";
    printChar(l);
    
    std::cout << "int: ";
    if (l < MIN_INT || l > MAX_INT) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(l) << std::endl;
    
    std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

// Convert float to all types
void convertFloat(const std::string& str)
{
    float f = std::atof(str.c_str());
    bool tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;
    
    std::cout << "char: ";
    printChar(f);
    
    std::cout << "int: ";
    if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    std::cout << "float: ";
    printFloat(f, tolerance);
    
    std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
}

// Convert double to all types
void convertDouble(const std::string& str)
{
    double d = std::atof(str.c_str());
    bool tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;
    
    std::cout << "char: ";
    printChar(d);
    
    std::cout << "int: ";
    printInt(d);
    
    std::cout << "float: ";
    printFloat(d, tolerance);
    
    std::cout << "double: ";
    printDouble(d);
}






static int	isSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return 1;
	return 0;
}

static int	isChar(const std::string& str, size_t& len)
{
	if (len == 1 && !isdigit(str[0]))
		return 1;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return 1;
	return 0;
}

static int	isInt(const std::string& str, size_t& len)
{
	int		i = 0;
	bool	flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

static int	isFloat(const std::string& str, size_t& len, size_t& dot)
{
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return 0;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return 0;
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return 0;
		if (str[i] == 'f' && i != len - 1)
			return 0;
	}
	return 1;
}

e_type findType(const std::string& str, size_t& len)
{
    size_t sep = str.find('.');
    size_t f = str.find('f');

    // If there is no dot, handle special types and basic types
    if (sep == std::string::npos)
    {
        if (isSpecial(str))
            return SPECIAL;
        if (isChar(str, len))
            return CHAR;
        if (isInt(str, len))
            return INT;
    }
    else  // There is a dot, could be a float or double
    {
        // If both a dot and 'f' are found, it's a float
        if (f != std::string::npos)
        {
            if (isFloat(str, len, sep))
                return FLOAT;
        }
        // If no 'f' is found, it's a double
        else
        {
            return DOUBLE;
        }
    }

    // Default return for unrecognized types
    return INVALID;
}


ScalarConverter::ScalarConverter(void)
{ }

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter(void)
{ }

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

void    ScalarConverter::convert(const std::string& str)
{
    size_t  len = str.length();
    e_type  type = findType(str, len);
    switch(type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case SPECIAL:
            printSpecial(str);
            break;
        case CHAR:
            convertChar(str, len);
            break;
        case INT:
            convertInt(str);
            break;
        case FLOAT:
            convertFloat(str);
            break;
        case DOUBLE:
            convertDouble(str);
            break;
    }
}