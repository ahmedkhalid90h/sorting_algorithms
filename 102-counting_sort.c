#include "sort.h"

/**
* counting_sort - counting sort algorithm implementation
* @array: array to be sorted by the
* @size: size of the array to be sorted by the algorithm
*/
void counting_sort(int *array, size_t size)
{
	int i, max_size;
	int *out_put = 0, *cp = NULL;
	size_t j, tmp, tal = 0;

	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (j = 0, max_size = 0; j < size; j++)
	{
		cp[j] = array[j];
		if (array[j] > max_size)
		{
			max_size = array[j];
		}
	}
	out_put = malloc(sizeof(int) * (max_size + 1));

	for (j = 0; j < size; j++)
	{
		out_put[array[j]] += 1;
	}
	for (i = 0; i <= max_size; i++)
	{
		tmp = out_put[i];
		out_put[i] = tal;
		tal += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[out_put[cp[j]]] = cp[j];
		out_put[cp[j]] += 1;
	}
	print_array(out_put, max_size + 1);
	free(out_put);
	free(cp);
}
