template<typename T>
void	iter(T *array, int arraySize, void (*fctToExecute)(const T &))
{
	for (int i = 0; i < arraySize; i++)
		fctToExecute(array[i]);
}