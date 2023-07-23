#include "sort.h"

/**
 * heapify - heapify function for
 * @array: array to be sorted by
 * @size: size of the array to be sorted (in bytes
 * @idx: index of the array to be sorted
 * @tal: total size of the array to be sorted
 */
void heapify(int *array, size_t size, int idx, size_t tal)
{
	int largest = idx, left = 2 * idx + 1, right = 2 * idx + 2, temp;

	if (left < (int)size && array[left] > array[largest])
		largest = left;
	if (right < (int)size && array[right] > array[largest])
		largest = right;
	if (largest != idx)
	{
		temp = array[idx];
		array[idx] = array[largest];
		array[largest] = temp;
		print_array(array, tal);
		heapify(array, size, largest, tal);
	}
}

/**
* heap_sort - heap sort algorithm for
* @array: array to be sorted by heap
* @size: size of the array to be sorted by heap
*/
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i != 0)
		{
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}
}
