#include "sort.h"

/**
 * merge - merge function
 * @array: array to be sorted
 * @temp: temporary array
 * @left: left index
 * @mid: middle index
 * @right: right index
*/
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;

	i = left, j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(temp + left, mid - left);
	printf("[right]: ");
	print_array(temp + mid, right - mid);
	/* While there are elements in the left or right runs... */
	for (k = left; k < right; k++)
	{
		/* If left run head exists and is <= existing right run head */
		if (i < mid && (j >= right || temp[i] <= temp[j]))
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}


/**
 * merge_sort_helper - merge sort helper function
 * @array: array to be sorted
 * @temp: temporary array
 * @left: left index
 * @right: right index
 */
void merge_sort_helper(int *array, int *temp, int left, int right)
{
	int mid;

	if (right - left < 2)
		return;

	mid = (right + left) / 2;
	merge_sort_helper(temp, array, left, mid);
	merge_sort_helper(temp, array, mid, right);
	merge(array, temp, left, mid, right);
}

/**
* merge_sort - merge sort algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void merge_sort(int *array, size_t size)
{
	int *temp, i;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		temp[i] = array[i];

	merge_sort_helper(array, temp, 0, size);
	free(temp);
}
