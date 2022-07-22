#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* main sorting function */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

/* helper functions */
void qs(int *arr, int low, int high, size_t size);
int partition(int *arr, int low, int high, size_t size);
listint_t *swap_nodes(listint_t *n, listint_t *b, listint_t *head);
void qsh(int *array, int low, int high, size_t size);
int partitionh(int *arr, int low, int high, size_t size);
void swap(int *array, int i, int j, size_t size);
int get_biggest_num(int *array, size_t size);
void fill_array(int *arra, int *arrb, size_t size);

void topdownmergesort(int *A, int *B, int n);
void splitmerge(int *array, int *array_c, size_t size, size_t l, size_t r);
void topdownmerge(int *array, int *array_c, size_t l, size_t m, size_t r);
void copyarray(int *A, int iBegin, int iEnd, int *B);


#endif
