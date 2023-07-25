#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of ints
 *                       in ascending order using Insertion sort algorithm.
 * @list: Double pointer to head of doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !*list || !(*list)->next)
        return;

    listint_t *current, *key, *prev;

    current = (*list)->next;

    while (current)
    {
        key = current;
        prev = current->prev;

        while (prev && prev->n > key->n)
        {
            /* Swap nodes */
            if (key->next)
                key->next->prev = prev;
            prev->next = key->next;
            key->prev = prev->prev;
            key->next = prev;
            prev->prev = key;

            if (key->prev)
                key->prev->next = key;
            else
                *list = key;

            print_list(*list);
            prev = key->prev;
        }
        current = current->next;
    }
}
