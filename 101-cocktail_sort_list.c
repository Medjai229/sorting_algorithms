#include "sort.h"

/**
 * swap_forward - Swap nodes from head to tail.
 * @list: pointer to the head of the list.
 * @tail: pointer to the tail of the list.
 * @current: pointer to the current swapping node.
 */
void swap_forward(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next)
		temp->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
	print_list(*list);
}

/**
 * swap_backward - Swap nodes from tail to head.
 * @list: pointer to the head of the list.
 * @tail: pointer to the tail of the list.
 * @current: pointer to the current swapping node.
 */
void swap_backward(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sort a doubly-linked list.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tail;
	int swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;

	do {
		swapped = 0;
		/* move forward */
		for (current = *list; current != tail; current = current->next)
			if (current->n > current->next->n)
			{
				swap_forward(list, &tail, &current);
				swap = 1;
			}

		/* move backward */
		for (current = current->prev; current != *list; current = current->prev)
			if (current->prev->n > current->n)
			{
				swap_backward(list, &tail, &current);
				swap = 1;
			}

	} while (swap);
}
