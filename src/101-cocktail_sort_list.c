#include "needed.c"

/**
 * cocktail_sort_list - function to sort a list with Cocktail shaker algorithm
 * @list: pointer to head pointer
 */

void cocktail_sort_list(listint_t **list) {
  size_t len, i, swaped;
  listint_t *first = NULL, *second = NULL;

  if (!list || !(*list))
    return;

  if ((len = listlen(*list)) < 2)
    return;

  do {
    swaped = 0;
    for (i = 0; i < len - 1; i++) {
      first = find_node(list, i);
      second = find_node(list, i + 1);
      if (first->n > second->n) {
        swap_nodes(first, second);
        reset_head(list);
        print_list(*list);
        swaped = 1;
      }
    }
    if (swaped == 0)
      break;
    swaped = 0;
    for (i = len - 2; i != 0; i--) {
      first = find_node(list, i);
      second = find_node(list, i + 1);
      if (first->n > second->n) {
        swap_nodes(first, second);
        reset_head(list);
        print_list(*list);
        swaped = 1;
      }
    }
  } while (swaped == 1);
}
