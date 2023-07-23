#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point for the
 *
 * Return: Always 0 on success and -1 on failure
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	size_t n = (sizeof(array) / sizeof(array[0]));

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
