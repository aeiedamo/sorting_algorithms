#include "needed.c"
#include "sort.h"

size_t main_size;
int *main_array;

size_t ileftchild(size_t i) { return (2 * i + 1); }
size_t irightchild(size_t i) { return (2 * i + 2); }
size_t iparent(size_t i) { return ((i - 1) / 2); }

void heapify(int *, size_t);
void siftDown(int *, size_t, size_t);

void heapify(int *array, size_t size) {
  size_t start = iparent(size - 1) + 1;

  while (start > 0) {
    start--;
    siftDown(array, start, size - 1);
  }
}

void siftDown(int *array, size_t root, size_t end) {
  size_t child;

  while (ileftchild(root) <= end) {
    child = ileftchild(root);

    if (child + 1 <= end && array[child] < array[child + 1])
      child++;
    if (array[root] < array[child]) {
      swap(&array[root], &array[child]);
      print_array(main_array, main_size);
      root = child;
    } else
      return;
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
    swap(&array[0], &array[end]);
    print_array(main_array, main_size);
    end--;
    siftDown(array, 0, end);
  }
}
