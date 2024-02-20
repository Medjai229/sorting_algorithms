#include "sort.h"

#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

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
 * siftdown - imlpement the siftdown operation
 * @array: pointer to the array
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 */
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t child, swapped, root = start;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		swapped = root;

		if (array[swapped] < array[child])
			swapped = child;

		if (child + 1 <= end && array[swapped] < array[child + 1])
			swapped = child + 1;

		if (swapped == root)
			return;

		swap(array, size, &array[root], &array[swapped]);
		root = swapped;
	}
}

/**
 * heapify - makes heap in place
 * @array: pointer to the array
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		siftdown(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in
 * ascending order using the Heap sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		siftdown(array, 0, end, size);
	}
}
