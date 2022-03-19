#include <cmath>
#include <string>
#include <limits>
#include <cstdlib>
#include "TypeAnalyst.hpp"

TypeAnalyst::TypeAnalyst(void)
{
	this->resetValues();
}

TypeAnalyst::TypeAnalyst(char *input)
{
	this->analyseNewInput(input);
}

TypeAnalyst::TypeAnalyst(const TypeAnalyst &src)
{
	*this = src;
}

TypeAnalyst::~TypeAnalyst(void)
{
}

TypeAnalyst &TypeAnalyst::operator=(const TypeAnalyst &rhs)
{
	this->_selectedType = rhs._selectedType;
	this->_charScalar = rhs._charScalar;
	this->_intScalar = rhs._intScalar;
	this->_floatScalar = rhs._floatScalar;
	this->_doubleScalar = rhs._doubleScalar;
	return *this;
}

void TypeAnalyst::analyseNewInput(char *input)
{
	this->resetValues();
	if (input[0] == 0)
		throw TypeAnalyst::EmptyInput();
	if (!this->getType(input))
		throw TypeAnalyst::CannotAnalyse();
	this->setVariable(input);
}

void TypeAnalyst::printTypes(void)
{
	if (this->_selectedType == TypeAnalyst::noType)
		std::cout << "No type set" << std::endl;
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

void TypeAnalyst::resetValues(void)
{
	this->_selectedType = TypeAnalyst::noType;
	this->_charScalar = 0;
	this->_intScalar = 0;
	this->_floatScalar = 0;
	this->_doubleScalar = 0;
}

bool TypeAnalyst::isdigit(char c) const
{
	return (c >= '0' && c <= '9');
}

bool TypeAnalyst::getType(char* input)
{
	this->_selectedType = handle_special_cases(input);
	if (this->_selectedType != TypeAnalyst::noType)
		return true;
	if ((input[0] >= '0' && input[0] <= '9') || input[0] == '-'
			|| input[0] == '.')
	{
		this->_selectedType = handle_numeric_values(input);
		if (this->_selectedType != TypeAnalyst::noType)
			return true;
	}
	if (input[1])
		return false;
	this->_selectedType = TypeAnalyst::charType;
	return true;
}

void TypeAnalyst::setVariable(char *input)
{
	if (this->_selectedType == TypeAnalyst::charType)
	{
		this->_charScalar = input[0];
	}
	else if (this->_selectedType == TypeAnalyst::intType)
	{
		this->_intScalar = atoi(input);
	}
	else if (this->_selectedType == TypeAnalyst::floatType)
	{
		this->_floatScalar = atof(input);
	}
	else if (this->_selectedType == TypeAnalyst::doubleType)
	{
		this->_doubleScalar = atof(input);
	}
}

int TypeAnalyst::handle_special_cases(char *input) const
{
	const std::string	special_doubles[] =
	{
		"inf", "+inf", "-inf", "nan"
	};
	const std::string	special_floats[] =
	{
		"inff", "+inff", "-inff", "nanf"
	};

	for (int i = 0; i < 4; i++)
	{
		if (special_doubles[i] == input)
			return TypeAnalyst::doubleType;
		else if (special_floats[i] == input)
			return TypeAnalyst::floatType;
	}
	return TypeAnalyst::noType;
}

int TypeAnalyst::handle_numeric_values(char *input) const
{
	int	i = 0;
	int	dotCount = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] == 'f' || input[i + 1] == 0))
		return (TypeAnalyst::noType);
	while (input[i] == '.' || isdigit(input[i]))
	{
		if (input[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return TypeAnalyst::noType;
		i++;
	}
	if (!input[i])
	{
		if (dotCount == 1)
			return TypeAnalyst::doubleType;
		return TypeAnalyst::intType;
	}
	else if (input[i] == 'f' && !input[i + 1] && dotCount == 1)
		return TypeAnalyst::floatType;
	return TypeAnalyst::noType;
}

void TypeAnalyst::printChar(void)
{
	if (this->_selectedType == TypeAnalyst::intType)
	{
		if (this->canConvertToChar(this->_intScalar))
			std::cout << "char: " << static_cast<char>(this->_intScalar) << std::endl;
	}
	else if (this->_selectedType == TypeAnalyst::floatType)
	{
		if (this->canConvertToChar(this->_floatScalar))
			std::cout << "char: " << static_cast<char>(this->_floatScalar) << std::endl;
	}
	else if (this->_selectedType == TypeAnalyst::doubleType)
	{
		if (this->canConvertToChar(this->_doubleScalar))
			std::cout << "char: " << static_cast<char>(this->_doubleScalar) << std::endl;
	}
	else
		std::cout << "char: " << this->_charScalar << std::endl;
}

bool TypeAnalyst::canConvertToChar(double number)
{
	if (number - static_cast<int>(number) != 0 || number > 127 || number < 0)
		std::cout << "char: impossible" << std::endl;
	else if (number <= 31 || number == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		return true;
	return false;
}

bool TypeAnalyst::canConvertToInt(double number)
{
	return (number <= std::numeric_limits<int>::max()
			&& number >= std::numeric_limits<int>::min()
			&& number != std::numeric_limits<double>::infinity()
			&& number != -std::numeric_limits<double>::infinity()
			&& number != std::numeric_limits<double>::quiet_NaN());
}

bool TypeAnalyst::canConvertToFloat(double number)
{
	return ((number <= std::numeric_limits<float>::max()
			&& number >= -std::numeric_limits<float>::max())
			|| number == std::numeric_limits<double>::infinity()
			|| number == -std::numeric_limits<double>::infinity()
			|| std::isnan(number));
}

void TypeAnalyst::printInt(void)
{
	if (this->_selectedType == TypeAnalyst::charType)
		std::cout << "int: " << static_cast<int>(this->_charScalar)
			<< std::endl;
	else if (this->_selectedType == TypeAnalyst::intType)
		std::cout << "int: " << this->_intScalar << std::endl;
	else if (this->_selectedType == TypeAnalyst::floatType)
	{
		if (canConvertToInt(this->_floatScalar))
			std::cout << "int: " << static_cast<int>(this->_floatScalar)
				<< std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
	else if (this->_selectedType == TypeAnalyst::doubleType)
	{
		if (canConvertToInt(this->_doubleScalar))
			std::cout << "int: " << static_cast<int>(this->_doubleScalar)
				<< std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
}

void TypeAnalyst::printFloat(void)
{
	if (this->_selectedType == TypeAnalyst::charType)
		std::cout << "float: " << static_cast<float>(this->_charScalar) << ".0f"
			<< std::endl;
	else if (this->_selectedType == TypeAnalyst::intType)
		std::cout << "float: " << static_cast<float>(this->_intScalar) << ".0f"
			<< std::endl;
	else if (this->_selectedType == TypeAnalyst::floatType)
		std::cout << "float: " << this->_floatScalar
			<< printDotZero(static_cast<float>(this->_floatScalar)) << "f"
			<< std::endl;
	else if (this->_selectedType == TypeAnalyst::doubleType)
	{
		if (canConvertToFloat(this->_doubleScalar))
			std::cout << "float: " << static_cast<float>(this->_doubleScalar)
				<< printDotZero(static_cast<float>(this->_doubleScalar)) << "f"
				<< std::endl;
		else
			std::cout << "float: impossible" << std::endl;
	}
}

void TypeAnalyst::printDouble(void)
{
	if (this->_selectedType == TypeAnalyst::charType)
		std::cout << "double: " << static_cast<double>(this->_charScalar)
			 << ".0" << std::endl;
	else if (this->_selectedType == TypeAnalyst::intType)
		std::cout << "double: " << static_cast<double>(this->_intScalar)
			<< ".0" << std::endl;
	else if (this->_selectedType == TypeAnalyst::floatType)
		std::cout << "double: " << static_cast<double>(this->_floatScalar)
			<< printDotZero(static_cast<double>(this->_floatScalar))
			<< std::endl;
	else if (this->_selectedType == TypeAnalyst::doubleType)
		std::cout << "double: " << this->_doubleScalar
			<< printDotZero(static_cast<double>(this->_doubleScalar))
			<< std::endl;
}

const char	*TypeAnalyst::printDotZero(double number)
{
	if (number - static_cast<int>(number) == 0.0)
		return (".0");
	return ("");
}