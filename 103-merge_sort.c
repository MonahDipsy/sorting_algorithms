#include "sort.h"

/**
 * merge_sort - sorting an array using mergse sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size + 1);
	if (!b)
		return;

	topdownmergesort(array, b, size);
	free(b);
}

/**
 * topdownmergesort - Top Down Merge Sort
 * @a: array a
 * @b: array b
 * @n: size of array
 * Return: void
 */

void topdownmergesort(int *a, int *b, int n)
{
	/* array int *a has the items to sort; array int *b is a work array.*/
	copyarray(a, 0, n, b);           /* one time copy of int *a to int *b */
	splitmerge(a, b, n, 0, n);   /* sort data from int *b into int *a */
}

/**
 * splitmerge - Top Down Split Merge
 * @array: array a
 * @array_c: arrayb
 * @size: start index
 * @l: end index
 * @r: array a
 * Return: void
 */

void splitmerge(int *array, int *array_c, size_t size, size_t l, size_t r)
{
	size_t i, mid;

	if ((r - l) <= 1)
		return;
	mid = (l + r) / 2;
	splitmerge(array, array_c, size, l, mid);
	splitmerge(array, array_c, size, mid, r);
	for (i = l; i <= r + (r == size ? -1 : 0); i++)
		array_c[i] = array[i];
	topdownmerge(array, array_c, l, mid, r);
}


/**
 * topdownmerge - Merges an array that has been split using the
 * top-down approach.
 * @array: The array to merge.
 * @array_c: The temporary array.
 * @l: The left index of the split-array.
 * @m: The mid-point of the split-array.
 * @r: The right index of the split-array.
 */

void topdownmerge(int *array, int *array_c, size_t l, size_t m, size_t r)
{
	size_t a = l, b = m, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + (m), r - m);
	for (c = l; c < r; c++)
	{
		if ((a < m) && ((b >= r) || (array_c[a] <= array_c[b])))
		{
			array[c] = array_c[a++];
		}
		else
		{
			array[c] = array_c[b++];
		}
	}
	printf("[Done]: ");
	print_array(array + l, r - l);
}

/**
 * copyarray - copies array a to array b from ibegin
 * to iend
 * @a: array a
 * @ibegin: start index
 * @iend: end index
 * @b: array b
 * Return: void
 */

void copyarray(int *a, int ibegin, int iend, int *b)
{
	int k;

	for (k = ibegin; k < iend; k++)
		b[k] = a[k];
}
