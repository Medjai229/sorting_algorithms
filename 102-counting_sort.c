#include "sort.h"

/**
 * max_value - get the max value in an array
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: the max value
 */
int max_value(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, k = max_value(array, size);

	if (array == NULL || size < 2)
		return;

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	memset(count, 0, sizeof(int) * (k + 1));

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
