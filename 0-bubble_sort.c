#include "sort.h"

/**
 * bubble_sort - sort array lements from min to max value in ascending order
 * @array: array to sort
 * @size: array size in bytes
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;
	int tmp;

	if (size <= 1)
	{
		return;
	}

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
