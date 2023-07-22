#include "sort.h"

/**
* radix_sort - radix sort algorithm (LSD)
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void radix_sort(int *array, size_t size)
{
	int i, j, k, max = 0, exp = 1, *output;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max / exp > 0)
	{
		int bucket[10] = {0};

		for (j = 0; j < (int)size; j++)
			bucket[(array[j] / exp) % 10]++;
		for (k = 1; k < 10; k++)
			bucket[k] += bucket[k - 1];
		for (j = size - 1; j >= 0; j--)
		{
			output[bucket[(array[j] / exp) % 10] - 1] = array[j];
			bucket[(array[j] / exp) % 10]--;
		}
		for (j = 0; j < (int)size; j++)
			array[j] = output[j];
		print_array(array, size);
		exp *= 10;
	}
	free(output);
}
