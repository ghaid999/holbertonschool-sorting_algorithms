#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		temp = curr->next; /* Save the next node before moving curr */
		while (curr->prev && curr->n < curr->prev->n)
		{
			prev = curr->prev;

			/* Detach curr and prev from their current links */
			prev->next = curr->next;
			if (curr->next)
				curr->next->prev = prev;

			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;

			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr; /* Update head if curr moved to start */

			print_list(*list);
		}
		curr = temp;
	}
}

