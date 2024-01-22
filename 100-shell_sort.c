#include "needed.c"
#include "sort.h"

/**
 * shell_sort - function to sort an array with shell short algorithm
 * @array: pointer to array
 * @size: size of array
 */

void shell_sort(int *array, size_t size) {
  size_t i, j, gap;

  for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
    ;

  for (; gap > 0; gap /= 3) {
    for (i = gap; i < size; i++) {
      j = i;
      while (j >= gap && array[j] < array[j - gap]) {
        swap(&array[j], &array[j - gap]);
        j -= gap;
      }
    }
    print_array(array, size);
  }
}
