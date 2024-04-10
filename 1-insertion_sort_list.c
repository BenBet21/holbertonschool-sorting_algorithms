#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to a pointer to the head of the list
 * Description: this function sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	listint_t *sorted = NULL;
	listint_t *current = *list;

	while (current != NULL)
	{
		listint_t *next = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
			sorted->prev = NULL;
		}
		else
		{
			listint_t *temp = sorted;

			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
			current->prev = temp;
		}

		print_list(sorted);
		current = next;
	}

	*list = sorted;
}
