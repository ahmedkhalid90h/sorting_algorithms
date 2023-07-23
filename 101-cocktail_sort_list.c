#include "sort.h"

/**
 *swap_left - swap a node for his previous one and return
 *@node: node to swap
 *@list: node list to swap
 *Return: return a pointer to a node which was enter it
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

/**
 *cocktail_sort_list - this is a cocktail sort implementation that
 *working on a double linked lists is not
 *@list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swpd = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		{
			return;
		}
	node = *list;
	while (swpd == 1)
	{
		swpd = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_left(node->next, list);
				swpd = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swpd == 0)
			{
				break;
			}
		swpd = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_left(node, list);
				swpd = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}
