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
 * count_radix - function to sort element with radix sort method
 * @array: the array of integers
 * @size: size of the array
 * @element_number: the number of digits in one number
 * @numbers: the numbers which must siorted by using radix
 */
void count_radix(int *array, size_t size, int element_number, int numbers)
{
    int maximum;

    if (element_number != (int)size)
        element_number = (int)size;

    if (element_number == numbers)
    {
        for (int i = 0; i < (int)size - 1; i++)
        {
            if (array[i + 1] != maximum)
            {
                swap_int(&array[i + 1], &maximum);
                print_array(array, numbers);
            }
        }

        for (int i = (int)size - 1; i >= 0; i--)
        {
            if (array[i] != maximum)
            {
                swap_int(&array[i], &maximum);
                print_array(array, numbers);
            }
        }
    }
}

/**
 * radix_sort - function to sort array of integrs using radix sort
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{

