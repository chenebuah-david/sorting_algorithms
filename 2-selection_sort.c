#include "sort.h"

/**
 * @a: The first integer that should be swapped.
 * @b: The second integer that should be swapped.
 * swap_ints - Swap two integers in an array.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - To sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of the integers.
 * @size: The size of the array.
 *
 * Description: It prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
