#include "needed.c"
#include "sort.h"

/**
 * selection_sort - function to sort an array with selection sort
 * @array: pointer to array
 * @size: size of array
 */

void selection_sort(int *array, size_t size) {
  unsigned int i, j, index_of_Min;

  if (size < 2)
    return;

  for (i = 0; i < size - 1; i++) {
    index_of_Min = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[index_of_Min]) {
        index_of_Min = j;
        continue;
      }
    }
    if (index_of_Min != i) {
      swap(&array[index_of_Min], &array[i]);
      print_array(array, size);
    }
  }
}
