#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list ussing insertion sorting algorithm
 * @list: pointer to the head of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *tmp;

	if (list == NULL || (*list) == NULL)
		return;
	head = *list;
	head = head->next;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		tmp = current->prev;
		while (current && tmp)
		{
			if (current->n < tmp->n)
			{
				if (current->prev != NULL)
				{
					current->prev->next = current->next;
				}
				if (current->next != NULL)
				{
					current->next->prev = current->prev;
				}
				current->next = tmp;
				if (tmp->prev)
					tmp->prev->next = current;
				current->prev = tmp->prev;
				tmp->prev = current;
				if (current->prev == NULL)
				{
					*list = current;
					print_list(*list);
					break;
				}
				tmp = current->prev;
				print_list(*list);
			} else
				tmp = tmp->prev;
		}
	}
}
