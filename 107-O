#include "sort.h"

/**
 * quick_sort_hoare - sort array using quick_sort_hoare partition
 * @array: array
 * @size: size of the array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsh(array, 0, (int)size - 1, size);
}

/**
 * qsh - quick sort recursive function
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 * Return: void
 */
void qsh(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now*/
		/*at right place */
		int p = partitionh(array, low, high, size);

		/* Separately sort elements before*/
		/* partition and after partition*/
		qsh(array, low, p - (p == high), size);
		qsh(array, p - (p == high) + 1, high, size);
	}
}
/**
 * partitionh - hoare partition implementation
 * @arr: array
 * @lo: lowest index
 * @hi: hghest index
 * @size: size of array
 * Return: new pivot index
 */

int partitionh(int *arr, int lo, int hi, size_t size)
{
	int pivot = arr[hi], i, j;

	i = lo - 1;

	j = hi + 1;

	while (1)
	{
		do {
			i += 1;
		} while (arr[i] < pivot);

		do {
			j -= 1;
		} while (arr[j] > pivot);

		if (i >= j)
			return (j);

		swap(arr, i, j, size);
	}
}

/**
 * swap - swap 2 indexes in an array
 * @array: array
 * @i: index 1
 * @j: index 2
 * @size: size of array
 * Return: void
 */

void swap(int *array, int i, int j, size_t size)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
	print_array(array, size);
}
