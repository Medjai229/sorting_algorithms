#include "sort.h"

/**
 * swap - swap two nodes in a doubly linked list
 * @x: pointer to the first node
 * @y: pointer to the second node
 */
void swap(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;

	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;

		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
