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

	listint_t *actuelle, *next, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	actuelle = *list;

	while (actuelle)
	{
		next = actuelle->next;
		prev = actuelle->prev;

		while (prev && prev->n > actuelle->n)
		{
			prev->next = actuelle->next;

			if (actuelle->next)
				actuelle->next->prev = prev;

			actuelle->next = prev;
			actuelle->prev = prev->prev;
			prev->prev = actuelle;

			if (actuelle->prev)
				actuelle->prev->next = actuelle;
			else
				*list = actuelle;
			prev = actuelle->prev;

			print_list(*list);
		}
		actuelle = next;
	}
}
