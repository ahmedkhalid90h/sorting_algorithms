#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers and a list of
 *
 * @array: Array to convert to a doubly linked list of integers
 * @size: Size of the array to convert
 *
 * Return: Pointer to the first of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmpe;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			{
				return (NULL);
			}
		tmpe = (int *)&node->n;
		*tmpe = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			{
				list->next->prev = list;
			}
	}
	return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list_pt;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list_pt = create_listint(array, n);
	if (!list_pt)
		{
			return (1);
		}
	print_list(list_pt);
	printf("\n");
	insertion_sort_list(&list_pt);
	printf("\n");
	print_list(list_pt);
	return (0);
}
