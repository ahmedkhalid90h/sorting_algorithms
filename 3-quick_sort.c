#include "sort.h"

/**
 *quick_sort - sorts an array with quick sort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}

/**
 *quickSort - quick sort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quickSort(int *array, int first, int last, int size)
{
	int position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		quickSort(array, first, position - 1, size);
		quickSort(array, position + 1, last, size);
	}
}

/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, int first, int last, int size)
{
	int pivot = array[last];
	int current = first, i;

	for (i = first; i <= last - 1; i++)
	{
		if (array[i] < pivot)
		{
			if (array[current] != array[i])
			{
				swap(&array[current], &array[i]);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(&array[current], &array[last]);
		print_array(array, size);
	}
	return (current);
}

/**
*swap - the positions of two elements into an array
*@a: array element
*@b: array element
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
