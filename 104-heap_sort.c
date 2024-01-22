#include "needed.c"
#include "sort.h"

size_t main_size;
int *main_array;

void heapify(int *, size_t);
void siftDown(int *, size_t, size_t);

void heapify(int *array, size_t size) {
  size_t start;

  start = (size - 1) / 2;
  while (start > 0) {
    start = start - 1;
    siftDown(array, start, size);
  }
}

void siftDown(int *array, size_t root, size_t end) {
  size_t child;

  while ((root * 2 + 1) <= end) {
    child = (root * 2) + 1;

    if (child + 1 <= end && array[child] < array[child + 1])
      child = child + 1;
    if (array[root] < array[child]) {
      swap(&array[root], &array[child]);
      print_array(main_array, main_size);
      root = child;
    } else {
      return;
    }
  }
}

void heap_sort(int *array, size_t size) {
  size_t end;

  if (!array || size < 2)
    return;

  main_size = size;
  main_array = array;

  heapify(array, size);
  end = size - 1;
  while (end > 0) {
    swap(&array[end], &array[0]);
    print_array(main_array, main_size);
    end = end - 1;
    siftDown(array, 0, end);
  }
}
