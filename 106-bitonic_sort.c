#include "sort.h"

/**
 * swap - swap two values in an array
 * @array: pointer to the array
 * @a: index of first value
 * @b: index of second value
 * @dir: bitonic direction (1 for ascending, 0 for descending)
 */
void swap(int *array, size_t a, size_t b, int dir)
{
	if ((array[a] > array[b] && dir == 1) || (array[a] < array[b] && dir == 0))
	{
		array[a] = array[a] + array[b];
		array[b] = array[a] - array[b];
		array[a] = array[a] - array[b];
	}
}

/**
 * bitonic_merge - does the merging step of the bitonic sort alogrithm
 * @array: pointer to the array
 * @index: the starting index for merging
 * @size: size of the array
 * @dir: bitonic direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t index, size_t size, int dir)
{
	size_t i, k = size / 2;

	if (size > 1)
	{
		for (i = index; i < index + k; i++)
			swap(array, i, i + k, dir);

		bitonic_merge(array, index, k, dir);
		bitonic_merge(array, index + k, k, dir);
	}
}

/**
 * bitonic - sorts a bitonic sequence recursively
 * @array: pointer to the array
 * @sub_size: current size of the subarray
 * @index: the starting index for sorting
 * @size: size of the array
 * @dir: bitonic direction (1 for ascending, 0 for descending)
 */
void bitonic(int *array, size_t sub_size, size_t index, size_t size, int dir)
{
	size_t new_size = sub_size / 2;
	char *s = (dir == 1) ? "UP" : "DOWN";

	if (sub_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sub_size, size, s);
		print_array(array + index, sub_size);

		bitonic(array, new_size, index, size, 1);
		bitonic(array, new_size, index + new_size, size, 0);
		bitonic_merge(array, index, sub_size, dir);

		printf("Result [%lu/%lu] (%s):\n", sub_size, size, s);
		print_array(array + index, sub_size);
	}
}

/**
 * bitonic_sort - sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: pointer of the array
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic(array, size, 0, size, 1);
}
