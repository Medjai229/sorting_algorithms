#include "sort.h"

/**
 * get_gap_size - calculate the gap size using knuth sequence
 * @size: size of the array
 *
 * Return: the gap size
 */
size_t get_gap_size(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = (gap * 3) + 1;

	return ((gap - 1) / 3);
}

/**
 * shell_sort - sorts an array of integers in
 * ascending order using the Shell sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	if (array == NULL)
		return;

	for (gap = get_gap_size(size); gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
