#include "sort.h"

/**
* counting_sort - counting sort algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *output = 0, *copy = NULL;
	size_t j, temp, total = 0;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	output = malloc(sizeof(int) * (max + 1));

	for (j = 0; j < size; j++)
		output[array[j]] += 1;
	for (i = 0; i <= max; i++)
	{
		temp = output[i];
		output[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[output[copy[j]]] = copy[j];
		output[copy[j]] += 1;
	}
	print_array(output, max + 1);
	free(output);
	free(copy);
}
