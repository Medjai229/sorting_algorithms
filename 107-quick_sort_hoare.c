#include "sort.h"

/**
 * swap - swap two values in an array
 * @array: pointer to the array
 * @a: first value
 * @b: second value
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: pointer to the array
 * @i: first value
 * @j: last value
 * @size: size of the array
 *
 * Return: new position of the last element sorted
 */
int hoare_partition(int *array, int i, int j, int size)
{
	int current = i - 1, finder = j + 1;
	int pivot = array[j];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * quick_recursive - recursivly sorting the array
 * @array: pointer to the array
 * @first: first value
 * @last: last value
 * @size: size of the array
 */
void quick_recursive(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		quick_recursive(array, first, position - 1, size);
		quick_recursive(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursive(array, 0, size - 1, size);
}
