#include "sort.h"

/**
 * sort_merge - merge sorted arrays
 * @array: pointer the to array
 * @start: the start of the array
 * @mid: the middle index of the sub arrays
 * @end: the end of the array
 * @temp: pointer to the temp array
 */
void sort_merge(int *array, int start, int mid, int end, int *temp)
{
	int i, m = mid, s = start;

	for (i = start; i < end; i++)
	{
		if (m < end && (s >= mid || temp[s] > temp[m]))
			array[i] = temp[m++];
		else
			array[i] = temp[s++];
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(temp + start, mid - start);
	printf("[right]: ");
	print_array(temp + mid, end - mid);
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * recursive_merge_sort - divide the array to sub arrays to be sorted
 * @array: pointer to the array
 * @start: the start of the array
 * @end: the end of the array
 * @temp: poiter to the temp array
 */
void recursive_merge_sort(int *array, int start, int end, int *temp)
{
	int mid = start + (end - start) / 2;

	if (end - start < 2)
		return;

	recursive_merge_sort(temp, start, mid, array);
	recursive_merge_sort(temp, mid, end, array);
	sort_merge(array, start, mid, end, temp);
}

/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	recursive_merge_sort(array, 0, size, temp);
	free(temp);
}
