#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - places the pivot at its correct position
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */

void quick_sort_recursive(int *array, int low, int high)
{

	if (low < high)
	{
		int pivot = partition(array, low, high);

		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
