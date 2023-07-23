#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - This gets the maximum value in an array of integers
 * @array: This is an array of integers
 * @size: This is the size of the array
 * Return: This is the maximum integer in the array
 */
int get_max(int *array, int size)
{
	int max, j;

	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	return (max);
}

/**
 * radix_counting_sort - This sorts significant digits of an array
 * of integers in ascending order using the counting sort algorithm
 * @array: This is an array of integers
 * @size: This is the size of the array
 * @sig: This is the significant digit to sort on
 * @buff: This is a buffer to store the sorted array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t j;

	for (j = 0; j < size; j++)
		count[(array[j] / sig) % 10] += 1;

	for (j = 0; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		buff[count[(array[j] / sig) % 10] - 1] = array[j];
		count[(array[j] / sig) % 10] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = buff[j];
}

/**
 * radix_sort - This sorts an array of integers in ascending
 * order using the radix sort algorithm
 * @array: This is an array of integers
 * @size: This is the size of the array
 * Description: This implements the LSD radix sort algorithm
 * This prints the array after each significant digit increase
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
