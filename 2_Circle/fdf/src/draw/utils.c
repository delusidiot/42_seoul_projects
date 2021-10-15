#include "fdf.h"

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? -a : a)

float float_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float float_mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}