#include "sort.h"
#include <stdint.h>

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
 * count_sort - sorts an array based on the expo
 * @array: pointer to the array
 * @size: size of the array
 * @expo: the exponent
 */
void count_sort(int *array, size_t size, int expo)
{
	size_t i, j;
	int count[10] = {0};
	int *output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / expo) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (j = size - 1; j != SIZE_MAX; j--)
	{
		output[count[(array[j] / expo) % 10] - 1] = array[j];
		count[(array[j] / expo) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int expo, max = max_value(array, size);

	if (array == NULL || size < 2)
		return;

	for (expo = 1; max / expo > 0; expo *= 10)
	{
		count_sort(array, size, expo);
		print_array(array, size);
	}
}
