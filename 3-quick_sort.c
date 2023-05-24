#include "sort.h"
/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
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

	if (array == NULL ||  size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
