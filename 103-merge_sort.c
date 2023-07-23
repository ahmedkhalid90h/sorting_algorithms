#include "sort.h"

/**
 * merge - merge function for sorting
 * @array: array to be sorted in ascending
 * @temp: temporary array to hold the
 * @left_idx: left index to be merged
 * @middle: middle index to be merged
 * @right_idx: right index to be merged
*/
void merge(int *array, int *temp, int left_idx, int middle, int right_idx)
{
	int i, j, k;

	i = left_idx, j = middle;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(temp + left_idx, middle - left_idx);
	printf("[right]: ");
	print_array(temp + middle, right_idx - middle);
	/* While there are elements in the left or right runs... */
	for (k = left_idx; k < right_idx; k++)
	{
		/* If left run head exists and is <= existing right run head */
		if (i < middle && (j >= right_idx || temp[i] <= temp[j]))
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
	print_array(array + left_idx, right_idx - left_idx);
}


/**
 * merge_sort_helper - merge sort helper function for sorting
 * @array: array to be sorted  index
 * @tmp: temporary array to hold the
 * @left_idx: left index to be merged
 * @right_idx: right index to be merged
 */
void merge_sort_helper(int *array, int *tmp, int left_idx, int right_idx)
{
	int mid;

	if (right_idx - left_idx < 2)
	{
		return;
	}

	mid = (right_idx + left_idx) / 2;
	merge_sort_helper(tmp, array, left_idx, mid);
	merge_sort_helper(tmp, array, mid, right_idx);
	merge(array, tmp, left_idx, mid, right_idx);
}

/**
* merge_sort - merge sort algorithm for
* @array: array to be sorted into
* @size: size of the array to be sorted into
*/
void merge_sort(int *array, size_t size)
{
	int *temp, i;

	if (array == NULL || size < 2)
	{
		return;
	}
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		return;
	}

	for (i = 0; i < (int)size; i++)
		{
			temp[i] = array[i];
		}

	merge_sort_helper(array, temp, 0, size);
	free(temp);
}
