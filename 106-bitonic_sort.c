#include "sort.h"

void swap_ints(int *b, int *c);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - This swaps two integers in an array
 * @b: This is the first integer to swap
 * @c: This is the second integer to swap
 */
void swap_ints(int *b, int *c)
{
	int tmp;

	tmp = *b;
	*b = *c;
	*c = tmp;
}

/**
 * bitonic_merge - This sorts a bitonic sequence inside an array of integers
 * @array: This is an array of integers
 * @size: This is the size of the array
 * @start: Starting index of the sequence in array to sort
 * @seq: This is the size of the sequence to sort
 * @flow: This is the direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Converts an array of integers into a bitonic sequence
 * @array: This is an array of integers
 * @size: This is the size of the array
 * @start: Starting index of a block of the building bitonic sequence
 * @seq: This is the size of a block of the building bitonic sequence
 * @flow: This is the direction to sort the bitonic sequence block in
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - This sorts an array of integers in ascending
 * order using the bitonic sort algorithm
 * @array: This is an array of integers
 * @size: This is the size of the array
 * Description: This prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
