#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Int stored in node
 * @prev: Pointer to prev element of list
 * @next: Pointer to next element of list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print funcs prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* bubble sort */
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */
