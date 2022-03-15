#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int goal)
{
	typename T::iterator result = find(container.begin(), container.end(), goal);

	if (result == container.end())
		return container.end();
	return result;
}
