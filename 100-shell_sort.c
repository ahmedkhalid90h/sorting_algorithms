#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * order using the Shell sort algorithm, using the Knuth sequence sort algorithm
 * @size: size of the array in ascending order
 * @array: list with numbers in ascending order
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i, idx = 0, tmp;

	if (array == NULL || size < 2)
		{
			return;
		}
	while (gap < size / 3)
		{
			gap = 3 * gap + 1;
		}
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			{
				for (idx = i; idx >= gap &&
				(array[idx] < array[idx - gap]); idx -= gap)
				{
					tmp = array[idx];
					array[idx] = array[idx - gap];
					array[idx - gap] = tmp;
				}
			}
		print_array(array, size);
		gap /= 3;
	}
}
