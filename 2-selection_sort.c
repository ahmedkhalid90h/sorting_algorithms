#include "sort.h"

/**
 * selection_sort - sort an array of integers using selection sort `
 *
 * @array: the array to order the integers
 * @size: the siz of the array to order the integers
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, min_idex;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min_idex = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idex])
				{
					min_idex = j;
				}
		if (min_idex != i)
		{
			tmp = array[min_idex];
			array[min_idex] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
