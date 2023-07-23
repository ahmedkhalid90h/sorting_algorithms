#include "sort.h"

/**
 *quick_sort - sorts an array with quick sort algorithm and returns
 *@array: array to sort
 *@size: array size to sort
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		{
			return;
		}
	quickSort(array, 0, size - 1, size);
}

/**
 *quickSort - quick sort algorithm implementation based on
 *@array: array to be sorted
 *@first_arr: first array element to be sorted
 *@last_arr: last array element to be sorted
 *@size: array size to be sorted
 */
void quickSort(int *array, int first_arr, int last_arr, int size)
{
	int position = 0;

	if (first_arr < last_arr)
	{
		position = lomuto_partition(array, first_arr, last_arr, size);
		quickSort(array, first_arr, position - 1, size);
		quickSort(array, position + 1, last_arr, size);
	}
}

/**
 *lomuto_partition - lomuto partition sorting scheme implementation based
 *@array: array of lomuto
 *@first_arr: first array element in first array
 *@last_arr: last array element in last array
 *@size: array size of first array
 *Return: return the position of the last element sorted in the first
 */
int lomuto_partition(int *array, int first_arr, int last_arr, int size)
{
	int pivot = array[last_arr];
	int curnt = first_arr, i;

	for (i = first_arr; i <= last_arr - 1; i++)
	{
		if (array[i] < pivot)
		{
			if (array[curnt] != array[i])
			{
				swap(&array[curnt], &array[i]);
				print_array(array, size);
			}
			curnt++;
		}
	}
	if (array[curnt] != array[last])
	{
		swap(&array[curnt], &array[last]);
		print_array(array, size);
	}
	return (curnt);
}

/**
*swap - the positions of two elements into an array of strings
*@ar: array element to be swapped
*@barr: array element to be swapped
*/
void swap(int *ar, int *barr)
{
	int temp;

	temp = *ar;
	*ar = *barr;
	*barr = temp;
}
