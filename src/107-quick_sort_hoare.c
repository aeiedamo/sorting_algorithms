#include "needed.c"

static int *main_array;
int main_size, set = 0;

/**
 * _partition_ - function to partition an array using hoare scheme
 * @array: pointer to array;
 * @low: the lower bound
 * @high: the higher bound
 * Return: the new index of pivot
 */

int _partition_(int *array, int low, int high) {
  int pivot, i, j;

  for (i = low, j = high, pivot = *(array + high);; i++, j--) {
    while (*(array + i) < pivot)
      i++;
    while (*(array + j) > pivot)
      j--;
    if (i >= j)
      return i;
    swap((array + i), (array + j));
    print_array(main_array, main_size);
  }
}

/**
 * quick_sort - function to sort an array with quick sort algorithm
 * using hoare scheme
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
  quick_sort_hoare(array, p);
  quick_sort_hoare(array + p, size - p);
}
