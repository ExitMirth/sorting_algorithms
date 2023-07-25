#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list of ints in ascending order
 *                        using Insertion sort algorithm.
 *
 * @list: Double pointer to head of doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;

    while (curr != NULL)
    {
        tmp = curr->prev;
        while (tmp != NULL && tmp->n > curr->n)
        {
            if (tmp->prev != NULL)
                tmp->prev->next = curr;
            else
                *list = curr;

            if (curr->next != NULL)
                curr->next->prev = tmp;

            tmp->next = curr->next;
            curr->prev = tmp->prev;
            curr->next = tmp;
            tmp->prev = curr;

            print_list(*list);

            tmp = curr->prev;
        }
        curr = curr->next;
    }
}
