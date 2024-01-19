#include "needed.c"
#include "sort.h"
/**
 * bubble_sort - function that uses bubble sort algorithm to sort an array
 * @array: pointer to array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size) {
  unsigned int i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        print_array(array, size);
      }
    }
  }
}
