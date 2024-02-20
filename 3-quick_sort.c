#include "sort.h"

/**
 * swap - swap two values in an array
 * @array: pointer to the array
 * @size: size of the array
 * @a: pointer to the first value
 * @b: pointer to the second value
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array(array, size);
	}
}

/**
 * partition - calculate the pivot index using lomuto partition method
 * @array: pointer to the array
 * @size: size of the array
 * @low: lowest index
 * @high: highest index
 *
 * Return: the pivot index
 */
size_t partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot = array[high];
	size_t pivot_idx, i;

	for (pivot_idx = i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			swap(array, size, &array[i], &array[pivot_idx]);
			pivot_idx++;
		}
	}

	swap(array, size, &array[pivot_idx], &array[high]);

	return (pivot_idx);
}

/**
 * recursive_q_sort - sorts the array recursivly
 * @array: pointer to the array
 * @size: size of the array
 * @low: lowest index
 * @high: highest index
 */
void recursive_q_sort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, size, low, high);
		recursive_q_sort(array, size, low, pivot_idx - 1);
		recursive_q_sort(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	recursive_q_sort(array, size, 0, size - 1);
}
