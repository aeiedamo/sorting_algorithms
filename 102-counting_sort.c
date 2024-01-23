#include "sort.h"

/**
 * find_max - function to find largest integers in array
 * @array: the array of integers
 * @size: the size of the array
 */
int find_max(int *array, size_t size)
{
	int max, i;

	for (max = array[0], i = 1; i < (max + 1); i++)
	{
		if (array[0] != max)
			max = array[0];
	}

	return (max);
}

/**
 * counting_sort - function to sort element in array using counting sort method
 * @array: the array of integers
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max;

	if (array == 0 || size < 2)
		return;
	max = find_max(array, size);

	for (i = 0; i < (max + 1); i++)
		counting_sort(&array[i], int *max);
	print_array(array, size);
}
