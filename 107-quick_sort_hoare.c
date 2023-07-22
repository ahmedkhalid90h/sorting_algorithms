#include "sort.h"

/**
 * hoare_partition - partitions array of integers using Hoare partition scheme
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - recursively sorts array of integers by separating into two
 * partitions, using Hoare quick sort
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	size_t border;

	if (low < high)
	{
		border = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, border, size);
		hoare_quicksort(array, border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order using a quick
 * sort, Hoare partition scheme alogrithm
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}
