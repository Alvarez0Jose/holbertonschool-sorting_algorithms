#include "sort.h"

/**
 * selection_sort - sorts an array of intergers in ascending order
 * @array: The array to be sorted
 * @size: the number of elements to be sorted
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, j, Midx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		Midx = idx;

		for (j = idx + 1; j < size; j++)
		{
			if (array[j] < array[Midx])
				Midx = j;
		}

		if (Midx != idx)
		{
			/* swap elements */
			temp = array[idx];
			array[idx] = array[Midx];
			array[Midx] = temp;

			/* print array after swap */
			print_array(array, size);
		}
	}
}
