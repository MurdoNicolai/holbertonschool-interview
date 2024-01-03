#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search_algos.h"

/**
*	advanced_binary - search valu in array
*	@array: pointer to the first element of the array to search in
*	@size: number of elements in array
*	@value: the value to search for
*	Return:  index where value is located
**/
int advanced_binary(int *array, size_t size, int value)
{

	size_t i;
	int half;
	int result;

	if (array == NULL)
		return (-1);

	printf("Searching in array:");
	for (i = 0; i < (size - 1); i++)
		printf(" %d,", array[i]);
	printf(" %d\n", array[i]);
	half = (size + 1) / 2;
	if (array[0] == value)
		return (0);

	if (array[half - 1] >= value)
	{
		result = advanced_binary(array, half, value);
		if (result == -1)
			return (-1);
		return (result);
	}

	else
	{
		if (size == 1)
			return (-1);
		result = advanced_binary((array + half), size - half, value);
		if (result == -1)
			return (-1);
		return (result + half);
	}

}
