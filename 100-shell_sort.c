#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i, idx = 0, temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (idx = i; idx >= gap &&
			 (array[idx] < array[idx - gap]); idx -= gap)
			{
				temp = array[idx];
				array[idx] = array[idx - gap];
				array[idx - gap] = temp;
			}
		print_array(array, size);
		gap /= 3;
	}
}
