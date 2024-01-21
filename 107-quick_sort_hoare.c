#include "needed.c"
#include "sort.h"

static int *main_array;
int main_size, set = 0;

/**
 * _partition_ - function to partition an array using lomuto scheme
 * @array: pointer to array;
 * @low: the lower bound
 * @high: the higher bound
 * Return: the new index of pivot
 */

int _partition_(int *array, int low, int high) {
  int *pivot = (array + low), i, j;

  for (i = low - 1, j = high + 1;;) {
    do {
      ++i;
    } while (*(array + i) < *pivot);
    do {
      --j;
    } while (*(array + j) > *pivot);
    if (i >= j)
      return j;
    swap((array + i), (array + j));
    print_array(main_array, main_size);
  }
}

/**
 * quick_sort_hoare - function to sort an array with quick sort algorithm
 * @array: pointer to array
 * @size: size of array
 */

void quick_sort_hoare(int *array, size_t size) {
  int p;

  if (!array || size < 2)
    return;

  if (set == 0) {
    main_array = array;
    main_size = size;
    set = 1;
  }

  p = _partition_(array, 0, size - 1);
  quick_sort_hoare(array, p + 1);
  quick_sort_hoare(array + p + 1, size - p - 1);
}
