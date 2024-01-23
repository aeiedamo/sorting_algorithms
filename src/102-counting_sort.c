#include "needed.c"
#include <stdlib.h>
#include <string.h>

/**
 * key - function to count how many times an item appears in a list
 * @array: pointer to array
 * @size: pointer to size
 * @item: the item to be looked up
 * Return: number to times items appeared
 */

size_t key(int *array, size_t size, size_t index) {
  size_t times = 0;

  if (array[size - 1] == array[index])
    times++;

  return (times);
}

/**
 * counting_sort - function to sort an array with counting sort algorithm
 * @array: pointer to array
 * @size: size of array
 */

void counting_sort(int *array, size_t size) {
  size_t i, j;
  int *count = NULL;

  if (!array || size < 2)
    return;

  count = malloc(size * sizeof(int));
  memset(count, 0, size * sizeof(int));
  for (i = 0; i < size - 1; i++) {
    j = key(array, size, i);
    printf("%lu", j);
    count[j]++;
  }

  for (i = 1; i < size; i++)
    count[i] = count[i] + count[i - 1];

  for (i = size - 1;; i--) {
    j = key(array, size, array[i]);
    count[j]--;
  }
  free(count);
}
