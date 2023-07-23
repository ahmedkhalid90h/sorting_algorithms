#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of insertion
 * of integers in ascending order using the Insertion sort algorithm described
 * @list: Dobule linked list to sort @list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		{
			return;
		}
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_left(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 *swap_left - swap a node for his previous one and return
 *@node: node to swap
 *@list: node list to swap
 *Return: return a pointer to a node which was enter it in the list
 */
listint_t *swap_left(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev, *current = node;

	prev->next = current->next;
	if (current->next)
		{
			current->next->prev = prev;
		}
	current->next = prev;
	current->prev = prev->prev;
	prev->prev = current;
	if (current->prev)
		{
			current->prev->next = current;
		}
	else
		{
			*list = current;
		}
	return (current);
}
