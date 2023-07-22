#include "sort.h"

/**
 * selection_sort - sort an array of integers using selection sort
 *
 * @array: the array to order
 * @size: the siz of the array to order
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		if (min_idx != i)
		{
			temp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = temp;
			print_array(array, size);

		}
	}
}
