#include "sort.h"

/**
 * swap_int - swaps two elements in array
 * @a: pointer to the first element to swap
 * @b: pointer to the second element to swap
 */

void swap_int(int *a, int *b)
{
	int tempNumber;

	tempNumber = *a;
	*a = *b;
	*b = tempNumber;
}

/**
 * hoare_partition - Organize numbers using the Hoare Partitioning method
 * @array: the array of integers
 * @size: size of the array
 * @minimum: the first element in the array
 * @maximum: the last element in the array
 * Return: The index after partitioning.
 */
int hoare_partition(int *array, size_t size, int maximum, int minimum)
{
	int pivot = array[maximum], left = array[minimum], z;

	for (z = minimum; z <= maximum - 1; z++)
	{
		do {
			maximum++;
		} while (array[z] < pivot);
		do {
			left--;
		} while (pivot < array[minimum]);

		if (left != minimum)
		{
			swap_int(&array[maximum], &array[minimum]);
			print_array(array, size);
		}
	}

	return (z);
}

/**
 * hoare_sort - Sort elements recursively with quicksort.
 * @array: the array of integers
 * @size: size of the array
 * @minimum: the first element in the array
 * @maximum: the last element in the array
 */
void hoare_sort(int *array, size_t size, int maximum, int minimum)
{
	int half;

	if (maximum -  minimum > 0)
	{
		half = hoare_partition(array, size, minimum, maximum);
		hoare_sort(array, size, minimum, half - 1);
		hoare_sort(array, size, half, maximum);
	}
}

/**
 * quick_sort_hoare - Arrange numbers in ascending order using the quick sort
 * @array: the array of integers
 * @size: the size of the array
 * Return: 0
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == 0 || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
