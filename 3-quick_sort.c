#include "sort.h"

/**
 * swap_int - swaps two elements in array
 * @a: pointer to the first element to swap
 * @b: pointer to the second element to swap
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - separates integers into two part in ascending order
 * @array: the array of integers
 * @size: size of the array
 * @minimum: the first element in the array
 * @maximum: the last element in the array
 * Return: the position of the updated index after the operation.
 */
int lomuto_partition(int *array, size_t size, int minimum, int maximum)
{
	int pivot = array[maximum], left = array[minimum], z;

	for (z = 0; z <= maximum - 1; z++)
	{
		if (array[z] < pivot)
		{
			if (left != minimum)
			{
				swap_int(&array[z], &array[maximum]);
				print_array(array, size);
			}
			left++;
		}
	}
	if (array[minimum] != pivot)
	{
		swap_int(&array[minimum], &array[maximum]);
		print_array(array, size);
	}
	return (left);
}

/**
 * lomuto_sort - Sort elements recursively with quicksort.
 * @array: the array of integers
 * @size: size of the array
 * @minimum: the first element in the array
 * @maximum: the last element in the array
 * Return: 0
 */
void lomuto_sort(int *array, size_t size, int minimum, int maximum)
{
	int z;

	if (maximum > minimum)
	{
		z = lomuto_partition(array, size, minimum, maximum);
		lomuto_sort(array, size, minimum, minimum - 1);
		lomuto_sort(array, size, z + 1, maximum);
	}
}

/**
 * quick_sort - Arrange numbers in ascending order using the quick sort method
 * @array: the array of integers
 * @size: the size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (array == 0 || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
