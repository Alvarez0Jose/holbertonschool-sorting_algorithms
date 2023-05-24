#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using the Insertion Sort algorithm
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	current = (*list)->next;
	while (current != NULL)
	{
		key = current;
		prev = current->prev;

		/* Move key to the correct position */
		while (prev != NULL && prev->n > key->n)
		{
			/* Swap the nodes */
			if (prev->prev != NULL)
				prev->prev->next = key;
			else
				*list = key;

			if (key->next != NULL)
				key->next->prev = prev;

			prev->next = key->next;
			key->prev = prev->prev;
			prev->prev = key;
			key->next = prev;

			/* Print the list after swapping nodes */
			print_list(*list);

			prev = key->prev;
		}

		current = current->next;
	}
}
