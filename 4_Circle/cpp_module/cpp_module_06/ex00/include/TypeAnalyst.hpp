#ifndef TYPEANALYST_HPP_
# define TYPEANALYST_HPP_

# include <iostream>
# include <stdexcept>

class TypeAnalyst
{
private:
	int		_selectedType;
	char	_charScalar;
	int		_intScalar;
	float	_floatScalar;
	double	_doubleScalar;

	void	resetValues(void);
	bool	getType(char *input);
	void	setVariable(char *input);
	int		handle_special_cases(char *input) const;
	int		handle_numeric_values(char *input) const;
	void	printChar(void);
	bool	isdigit(char c) const;
	bool	canConvertToChar(double number);
	bool	canConvertToInt(double number);
	bool	canConvertToFloat(double number);
	
	void	printInt(void);
	void	printFloat(void);
	void	printDouble(void);
	const char	*printDotZero(double number);

	static const int noType = -1;
	static const int charType = 0;
	static const int intType = 1;
	static const int floatType = 2;
	static const int doubleType = 3;
public:
	TypeAnalyst(void);
	TypeAnalyst(char *input);
	TypeAnalyst(const TypeAnalyst &src);
	~TypeAnalyst(void);

	TypeAnalyst	&operator=(const TypeAnalyst &rhs);

	void	analyseNewInput(char *input);
	void	printTypes(void);

	class EmptyInput: public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Please enter an input to be analysed by the converter";
		}
	};

	class CannotAnalyse: public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "The input is not a valid char, int, float or double";
		}
	};
};

#endif