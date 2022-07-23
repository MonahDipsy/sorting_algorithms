#include "sort.h"

/**
 * selection_sort - sorts an array using the selection algorithm
 * @array: pointer to array
 * @size: size of the array
 * Returns: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, selec_idx;
	int selec_val;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		selec_val = array[i];
		selec_idx = i;
		for (j = i; j < size; j++)
		{
			if (selec_val > array[j])
			{
				selec_idx = j;
				selec_val = array[j];
			}
		}
		if (selec_val == array[i] && selec_idx == i)
			continue;
		array[selec_idx] = array[i];
		array[i] = selec_val;
		print_array(array, size);
	}
}
