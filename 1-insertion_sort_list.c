#include "needed.c"
#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - function to sort a linked list with insertion sort
 * @list: double pointer to list
 */

void insertion_sort_list(listint_t **list) {
  listint_t *first, *second, *third;
  int i, j;
  int len = listlen(*list);
  if (!list || !(*list))
    return;

  for (i = 1; i < len; i++) {
    first = find_node(list, i);
    for (j = i - 1; j >= 0; j--) {
      second = find_node(list, j);
      if (second->n <= first->n)
        break;
      third = find_node(list, j + 1);
      swap_nodes(third, second);
      reset_head(list);
      print_list(*list);
    }
  }
}
