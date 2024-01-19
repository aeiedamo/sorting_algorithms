#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
#include <unistd.h>
=======
#include <stddef.h>

>>>>>>> 25bd1ac13226c720f44da80c35ff01773a90cf63
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
<<<<<<< HEAD
 * @prev: Pointer to the previous element of the listint_s
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s {
  const int n;
  struct listint_s *prev;
  struct listint_s *next;
} listint_t;

void reset_head(listint_t **list);
void swap_nodes(listint_t *i, listint_t *j);
listint_t *find_node(listint_t **list, int n);
int listlen(listint_t *list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *i, int *j);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

#endif /* !SORT_H */
=======
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
>>>>>>> 25bd1ac13226c720f44da80c35ff01773a90cf63
