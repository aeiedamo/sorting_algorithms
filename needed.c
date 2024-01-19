#include "sort.h"
#include <stdlib.h>

/**
 * reset_head - function to reset head of a list
 * @list: pointer to so-called head
 */

void reset_head(listint_t **list) {

  while ((*list)->prev) {
    (*list) = (*list)->prev;
  }
}

/**
 * swap_nodes - function to swap 2 nodes pointers
 * @i: first node pointer
 * @j: second node pointer
 */

void swap_nodes(listint_t *i, listint_t *j) {
  listint_t *tmp = malloc(sizeof(listint_t));

  if (i->next) {
    tmp->next = i->next;
    i->next->prev = tmp;
  } else {
    tmp->next = NULL;
  }
  if (i->prev) {
    tmp->prev = i->prev;
    i->prev->next = tmp;
  } else {
    tmp->prev = NULL;
  }

  if (j->next) {
    i->next = j->next;
    j->next->prev = i;
  } else {
    i->next = NULL;
  }
  if (j->prev) {
    i->prev = j->prev;
    j->prev->next = i;
  } else {
    i->prev = NULL;
  }

  if (tmp->next) {
    j->next = tmp->next;
    tmp->next->prev = j;
  } else {
    j->next = NULL;
  }
  if (tmp->prev) {
    j->prev = tmp->prev;
    tmp->prev->next = j;
  } else {
    j->prev = NULL;
  }

  free(tmp);
}

/**
 * find_element - function to find the Nth element in a linked list
 * @list: pointer to head of list
 * @n: index of element
 * Return: the integer value at that node
 */

listint_t *find_node(listint_t **list, int n) {
  listint_t *tmp = *list;
  if (!list)
    return NULL;

  for (; n > 0; n--)
    tmp = tmp->next;

  return (tmp);
}

/**
 * listlen - to find length of a linked list
 * @list: pointer to head of list
 * Return: length of a linked list
 */

int listlen(listint_t *list) {
  int len;
  listint_t *tmp = list;
  if (!tmp)
    return -1;

  for (len = 0; tmp; tmp = tmp->next, len++)
    ;

  return len;
}

/**
 * swap - function to swap 2 integers
 * @i: 1st integer
 * @j: 2nd integer
 */

void swap(int *i, int *j) {
  int tmp = *i;

  *i = *j;
  *j = tmp;
}
