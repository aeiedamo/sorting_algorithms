#include "needed.c"
#include "sort.h"

size_t main_size, set = 0;
int *main_array;

int quick_sort0(int *array, size_t start, size_t end) {
  int *pivot = array + end;
  size_t i, j;

  i = start;

  for (j = start; j < end; j++) {
    if (*(array + j) <= *pivot) {
      swap((array + j), (array + i));
      i++;
    }
  }
  swap((array + i), pivot);
  print_array(main_array, main_size);
  return i;
}

void quick_sort(int *array, size_t size) {
  int pivot_index;

  if (!array || size < 2)
    return;

  if (set == 0) {
    main_size = size;
    main_array = array;
    set = 1;
  }
  pivot_index = quick_sort0(array, 0, size - 1);
  quick_sort(array, pivot_index);
  quick_sort(array + pivot_index + 1, size - pivot_index - 1);
}
