#include <algorithm>
#include <cstdlib>
#include <iterator>
#include "span.hpp"

Span::Span(void): _storedSize(0)
{

}

Span::Span(unsigned int storedSize): _storedSize(storedSize),
	_storage(0)
{

}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span(void)
{

}

Span &	Span::operator=(Span const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_storedSize = rhs._storedSize;
	this->_storage = rhs._storage;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Span const &instance)
{
	int	shortest = instance.shortestSpan();
	int	longest = instance.longestSpan();

	os << "Span of max size " << instance.maxSize() << " contains "
		<< instance.size() << " numbers, shortest span is "
		<< shortest << " and longest is " << longest;
	return os;
}

void	Span::addNumber(int number)
{
	if (_storage.size() == _storedSize)
		throw std::out_of_range("Cannot add any more numbers");
	_storage.push_back(number);
}

void	Span::randomFill(void)
{
	unsigned int	numbersToFill = this->spaceLeft();

	for (unsigned int i = 0; i < numbersToFill; i++)
		this->addNumber(rand() % (this->maxSize() * 10));
}

void	Span::addByIteratorRange(std::vector<int>::iterator begin,
		std::vector<int>::iterator end)
{
	std::vector<int>	tmp(begin, end);

	if (tmp.size() > this->spaceLeft())
		throw std::out_of_range("Cannot add any more numbers");
	copy(tmp.begin(), tmp.end(), std::back_inserter(this->_storage));
}

int	Span::shortestSpan(void) const
{
	std::vector<int>			tmp = _storage;
	int							result = -1;
	std::vector<int>::iterator	it;

	if (_storage.size() <= 1)
		throw std::logic_error("Not enough numbers stored to provide a span");
	sort(tmp.begin(), tmp.end());
	result = *(tmp.begin() + 1) - *tmp.begin();
	if (this->size() == 2)
		return result;
	for (it = tmp.begin() + 1; it != tmp.end() - 1 && result != 0; it++)
	{
		if (*(it + 1) - *it < result)
			result = *(it + 1) - *it;
	}
	return result;
}

int	Span::longestSpan(void) const
{
	std::vector<int>	tmp = _storage;

	if (_storage.size() <= 1)
		throw std::logic_error("Not enough numbers stored to provide a span");
	sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

unsigned int	Span::size(void) const
{
	return _storage.size();
}

unsigned int	Span::maxSize(void) const
{
	return _storedSize;
}

unsigned int	Span::spaceLeft(void) const
{
	return maxSize() - size();
}