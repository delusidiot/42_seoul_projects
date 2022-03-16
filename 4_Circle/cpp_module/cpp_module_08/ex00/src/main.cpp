#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

template<typename T>
void	displayIterator(T it, T end)
{
	if (it != end)
		std::cout << "iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

void test1(void)
{
	std::vector<int>			vect;
	std::vector<int>::iterator	it;

	for (int i = 1; i < 59; i += 2)
		vect.push_back(i);
	it = easyfind(vect, 43);
	displayIterator(it, vect.end());
	it = easyfind(vect, 42);
	displayIterator(it, vect.end());
}

void test2(void)
{
	std::deque<int> d;
	std::list<int> l;
	std::vector<int> v;

	for (int i = 0 ; i < 10 ; ++i) {
		d.push_back(i);
		l.push_back(i);
		v.push_back(i);
	}
	{
		std::deque<int>::iterator iter = easyfind(d, 3);
		displayIterator(iter, d.end());
	}
	
	{
		std::list<int>::iterator iter = easyfind(l, 6);
		displayIterator(iter, l.end());
	}
	{
		std::vector<int>::iterator iter = easyfind(v, 10);
		displayIterator(iter, v.end());
	}
}

int	main(void)
{
	test1();
	test2();
	return 0;
}
