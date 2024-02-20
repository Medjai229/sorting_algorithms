#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_val;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_val])
				min_val = j;

		if (array[i] > array[min_val])
		{
			temp = array[min_val];
			array[min_val] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
