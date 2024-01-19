#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void) {
  int array[] = {432, 896, 175, 586, 786, 367, 297, 628, 9,   534,
                 625, 652, 149, 447, 902, 873, 884, 698, 229, 877};
  size_t n = sizeof(array) / sizeof(array[0]);

  print_array(array, n);
  printf("\n");
  selection_sort(array, n);
  printf("\n");
  print_array(array, n);
  return (0);
}
