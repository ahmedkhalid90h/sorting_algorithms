#include "sort.h"

/**
* bitonic_compare - compare sub-arrays
* @up: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
*/
void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, eva;
	int swap;

	eva = size / 2;
	for (i = 0; i < eva; i++)
	{
		if ((array[i] > array[i + eva]) == up)
		{
			swap = array[i];
			array[i] = array[i + eva];
			array[i + eva] = swap;
		}
	}
}

/**
* bitonic_merge - recursion to mergess sub-arrays
* @up: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
*
* Return: void
*/
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
* bit_sort - recursive bitonic sort algorithm
* @up: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
* @t: total size of the original array
*
* Return: void
*/
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);

	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
* bitonic_sort - bitonic sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
