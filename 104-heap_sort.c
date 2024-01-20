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
 * build_max_heapify - Make a special kind of heap from a tree to  organized.
 * @array: the array of integers
 * @size: size of the array
 * @parent: the base row in the tree.
 * @child: the root row in the tree.
 */
void build_max_heapify(int *array, size_t size, size_t parent, size_t child)
{
	size_t max_heap, mini_heap;

	max_heap = array[parent];
	mini_heap = array[child];

	if (parent != max_heap)
	{
		swap_int(&array[max_heap], &array[parent]);
		print_array(array, size);
		build_max_heapify(array, size, parent, max_heap);
	}
	if (child != mini_heap)
	{
		swap_int(&array[mini_heap], &array[child]);
		print_array(array, size);
		build_max_heapify(array, size, child, mini_heap);
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

	if (array == 0 || size < 2)
		return;

	for (z = 0; z <= (size / 2) - 1; z++)
	{

	build_max_heapify(array, size, 0, size - 1);
	}

	for (z = 0; z < size - 1; z++)
	{
		swap_int(array + z, array + (size - 1));
		print_array(array, size);
		build_max_heapify(array, size, z, 0);
	}
}
