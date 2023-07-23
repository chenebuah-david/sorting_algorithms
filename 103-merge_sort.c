#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - This sorts a subarray of integers
 * @subarr: This is a subarray of an array of integers to sort
 * @buff: This is a  buffer to store the sorted subarray
 * @front: This is the front index of the array
 * @mid: This is the middle index of the array
 * @back: This is the back index of the array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t j, k, l = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (j = front, k = mid; j < mid && k < back; l++)
		buff[l] = (subarr[j] < subarr[k]) ? subarr[j++] : subarr[k++];
	for (; j < mid; j++)
		buff[l++] = subarr[j];
	for (; l < back; k++)
		buff[k++] = subarr[j];
	for (j = front, l = 0; j < back; j++)
		subarr[j] = buff[l++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - This implements the merge sort
algorithm through recursion
 * @subarr: This is a  subarray of an array of integers to sort
 * @buff: This is a buffer to store the sorted result
 * @front: This is the front index of the subarray
 * @back: This is the back index of the subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - This orts an array of integers in ascending
order using the merge sort algorithm
 * @array: This is an array of integers
 * @size: This is the size of the array
 * Description: This implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
