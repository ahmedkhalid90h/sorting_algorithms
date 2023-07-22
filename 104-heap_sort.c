#include "sort.h"

/**
 * heapify - heapify function
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * @i: index
 * @total: total size of the array
 */
void heapify(int *array, size_t size, int i, size_t total)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2, temp;

	if (left < (int)size && array[left] > array[largest])
		largest = left;
	if (right < (int)size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, total);
		heapify(array, size, largest, total);
	}
}

/**
* heap_sort - heap sort algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
