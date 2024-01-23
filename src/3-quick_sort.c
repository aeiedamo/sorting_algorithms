#include "needed.c"

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
  int *pivot = (array + high);
  int i = low - 1, j;

  for (j = low; j < high; j++) {
    if (*(array + j) <= *pivot) {
      ++i;
      if (i == j)
        continue;
      swap((array + j), (array + i));
      print_array(main_array, main_size);
    }
  }
  ++i;
  if (*(array + i) != *(array + high)) {
    swap((array + i), (array + high));
    print_array(main_array, main_size);
  }
  return i;
}

/**
 * quick_sort - function to sort an array with quick sort algorithm
 * @array: pointer to array
 * @size: size of array
 */

void quick_sort(int *array, size_t size) {
  int p;

  if (!array || size < 2)
    return;

  if (set == 0) {
    main_array = array;
    main_size = size;
    set = 1;
  }

  p = _partition_(array, 0, size - 1);
  quick_sort(array, p);
  quick_sort(array + p + 1, size - p - 1);
}
