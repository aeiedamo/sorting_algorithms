#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void) {
  int array[] = {785, 324, 816, 255, 601, 249, 572, 93,  415, 346,
                 226, 379, 861, 270, 593, 302, 707, 271, 706, 728};
  size_t n = sizeof(array) / sizeof(array[0]);

  print_array(array, n);
  printf("\n");
  bubble_sort(array, n);
  printf("\n");
  print_array(array, n);
  return (0);
}
