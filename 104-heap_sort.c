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
 * max_heapify - Make a special kind of heap from a tree to  organized.
 * @array: the array of integers
 * @size: size of the array
 * @parent: the base row in the tree.
 * @child: the root row in the tree.
 */
void max_heapify(int *array, size_t size, size_t parent, size_t child)
{
	size_t left_child, right_child, maximum;

	left_child = 2 * child + 1;
	right_child = 2 * child + 2;
	maximum = parent;

	if (left_child < parent && array[left_child] > array[maximum])
		maximum = left_child;

	if (right_child < parent && array[right_child] > array[maximum])
		maximum = right_child;

	if (maximum != parent)
	{
		swap_int(array + maximum, array + parent);
		print_array(array, size);
		max_heapify(array, size, parent, maximum);
	}
}

/**
 * heap_sort - Arrange numbers in ascending order using the heap sort
 * @array: the array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t z;

	if (array == NULL || size < 2)
		return;

	for (z = (size / 2) - 1; z != size + 1; z--)
	{
		max_heapify(array, size, size, z);
	}

	for (z = size - 1; z > 0; z--)
	{
		swap_int(array, array + z);
		print_array(array, size);
		max_heapify(array, size, z, 0);
	}
}
