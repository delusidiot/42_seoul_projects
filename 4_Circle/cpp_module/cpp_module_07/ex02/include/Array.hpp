#ifndef ARRAY_HPP_
# define ARRAY_HPP_

# include <iostream>

template<typename T>
class Array
{
private:
	int		_size;
	T		*_array;
public:
	Array<T>(void): _size(0), _array(NULL)
	{
		std::cout << "Empty constructor called" << std::endl;
	}
	Array<T>(const unsigned int size): _size(size)
	{
		std::cout << "Size constructor called" << std::endl;
		if (size < 0)
			throw std::overflow_error("Index out of bounds");
		this->_array = new T[size];
	}
	Array<T>(const Array<T> &src)
	{
		std::cout << "Copy constructor called" << std::endl;
		*this = src;
	}
	~Array<T>(void)
	{
		std::cout << "Destructor called" << std::endl;
		if (this->_size >= 0)
			delete[] this->_array;
	}

	Array<T>	&operator=(const Array<T> &rhs)
	{
		std::cout << "Assignation overload called" << std::endl;
		if (this == &rhs)
			return *this;
		if (this->_size >= 0)
			delete[] this->_array;
		this->_size = rhs.getSize();
		this->_array = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = rhs[i];
		return *this;
	}
	T			&operator[](const int idx) const
	{
		if (idx >= this->_size || idx < 0)
			throw std::overflow_error("Index out of bounds");
		return this->_array[idx];
	}

	int			getSize(void) const
	{
		return this->_size;
	}
};

template<typename T>
std::ostream	&operator<<( std::ostream &ostr, const Array<T> &instance );

#endif