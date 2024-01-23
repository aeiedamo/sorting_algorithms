#include "needed.c"
/**
 * topDownMerge - function to merge the left and right of an array
 * @arrayB: pointer to B array
 * @start: start of arrays
 * @mid: mid of arrays
 * @end: end of arrays
 * @array: pointer to array A
 */

void topDownMerge(int *arrayB, size_t start, size_t mid, size_t end,
                  int *array) {
  size_t i = start, j = mid, k;

  for (k = start; k < end; k++) {
    if (i < mid && (j >= end || array[i] <= array[j])) {
      arrayB[k] = array[i];
      i++;
    } else {
      arrayB[k] = array[j];
      j++;
    }
  }
}

/**
 * topDownSplitMerge - function to split an array into left and right
 * @arrayB: pointer to array B
 * @start: start of arrays
 * @end: end of arrays
 * @array: pointer to array A
 */

void topDownSplitMerge(int *arrayB, size_t start, size_t end, int *array) {
  size_t mid;

  if (end - start < 2)
    return;
  mid = (start + end) / 2;
  topDownSplitMerge(array, start, mid, arrayB);
  topDownSplitMerge(array, mid, end, arrayB);
  printf("Merging...\n[left]: ");
  print_array(array + start, mid - start);
  printf("[right]: ");
  print_array(array + mid, end - mid);
  topDownMerge(arrayB, start, mid, end, array);
  printf("[Done]: ");
  print_array(arrayB + start, end - start);
}

/**
 * copy_array - function to copy array A to B
 * @array: pointer to array A
 * @size: size of arrays
 * @arrayB: pointer to array B
 */

void copy_array(int *array, size_t size, int *arrayB) {
  size_t i;
  for (i = 0; i < size; i++)
    arrayB[i] = array[i];
}

/**
 * merge_sort - function to sort an array using merge sort algorithm
 * @array: pointer to array
 * @size: size of array
 */

void merge_sort(int *array, size_t size) {
  int *arrayB = NULL;

  if (!array || size < 2)
    return;

  arrayB = malloc(size * sizeof(int));
  if (!arrayB)
    return;
  copy_array(array, size, arrayB);
  topDownSplitMerge(array, 0, size, arrayB);
  free(arrayB);
}
