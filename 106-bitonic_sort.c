#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * bitonic_merge - Merges the items in a sub-array based on a given order.
 * @array: The array to sort.
 * @size: The length of the array (should be a power of 2).
 * @low: The starting position of the sub-array.
 * @n: The length of the sub-array.
 * @ascending: A flag specifying the direction of the items in this sub-array.
 */
void bitonic_merge(int *array, size_t size,
									 size_t low, size_t n, char ascending)
{
	size_t i, m;

	if ((array != NULL) && (n > 1))
	{
		m = n / 2;
		for (i = low; i < (low + m); i++)
		{
			if ((array[i] > array[i + m]) == ascending)
			{
				swap_items(array, i, i + m);
			}
		}
		bitonic_merge(array, size, low, m, ascending);
		bitonic_merge(array, size, low + m, m, ascending);
	}
}

/**
 * bitonic_sort_split - Sorts a sub-array using the bitonic algorithm.
 * @array: The array to sort.
 * @size: The length of the array (should be a power of 2).
 * @low: The starting position of the sub-array.
 * @n: The length of the sub-array.
 * @ascending: A flag specifying the direction of the items in this sub-array.
 */
void bitonic_sort_split(int *array, size_t size,
												size_t low, size_t n, char ascending)
{
	size_t m;

	if ((array != NULL) && (n > 1))
	{
		m = n / 2;
		printf("Merging [%d/%d] (%s):\n",
					(int)(n), (int)size, ascending ? "UP" : "DOWN");
		print_array(array + low, n);
		bitonic_sort_split(array, size, low, m, TRUE);
		bitonic_sort_split(array, size, low + m, m, FALSE);
		bitonic_merge(array, size, low, n, ascending);
		printf("Result [%d/%d] (%s):\n",
					(int)(n), (int)size, ascending ? "UP" : "DOWN");
		print_array(array + low, n);
	}
}

/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array (should be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		bitonic_sort_split(array, size, 0, size, TRUE);
	}
}
