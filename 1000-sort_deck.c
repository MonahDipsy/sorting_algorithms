#include "deck.h"

/**
 * val_cmp - Performs a case-insensitive character comparison of two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: The comparison value. -1 for less, 1 for greater, and 0 for equal.
 */
int val_cmp(const char *str1, const char *str2)
{
	int i = 0;
	char a, b;

	if (str1 == NULL)
		return (str2 == NULL ? 0 : -1);
	if (str2 == NULL)
		return (1);
	for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		a = ((str1[i] >= 'A') && (str1[i] <= 'Z') ? str1[i] + 32 : str1[i]);
		b = ((str2[i] >= 'A') && (str2[i] <= 'Z') ? str2[i] + 32 : str2[i]);
		if (a > b)
			return (1);
		else if (a < b)
			return (-1);
	}
	if (str1[i] == '\0')
		return (str2[i] == '\0' ? 0 : -1);
	return (1);
}

/**
 * card_key - Computes the sorting key of a playing card.
 * @card: The playing card.
 *
 * Return: The key that can be used to sort the card.
 */
int card_key(const card_t *card)
{
	int rank = -1, base = 0, i = 0;
	char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"Jack", "Queen", "King", NULL
	};

	if (card == NULL)
		return (-2);
	while (values[i] != NULL)
	{
		if (val_cmp(card->value, values[i]) == 0)
		{
			rank = base + i;
			break;
		}
		i++;
	}
	return (rank + (13 * card->kind));
}

/**
 * swap_nodes - Swaps two nodes in a linked list.
 * @list: A pointer to the head of the linked list.
 * @l: The left item to swap.
 * @r: The right item to swap.
 */
void swap_nodes(deck_node_t **list, deck_node_t *l, deck_node_t *r)
{
	deck_node_t *tmp0 = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;

	if ((l == NULL) || (r == NULL) || (list == NULL) || (l == r))
		return;
	tmp0 = l->prev, tmp1 = l->next, tmp2 = r->prev, tmp3 = r->next;
	if (l->prev == r)
	{
		l->next = r, l->prev = tmp2, r->next = tmp1, r->prev = l;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp1 != NULL)
			tmp1->prev = r;
	}
	else if (l->next == r)
	{
		l->next = tmp3, l->prev = r, r->next = l, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	else
	{
		l->next = tmp3, l->prev = tmp2, r->next = tmp1, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp1 != NULL)
			tmp1->prev = r;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	if (l->prev == NULL)
		*list = l;
	if (r->prev == NULL)
		*list = r;
}

/**
 * sort_deck - Sorts a deck of cards using the insertion sort algorithm.
 * @deck: The deck of cards to sort.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node0 = NULL, *node1 = NULL, *node2 = NULL, *tmp = NULL;

	if (deck != NULL)
	{
		node0 = *deck == NULL ? NULL : (*deck)->next;
		while (node0 != NULL)
		{
			node1 = node0;
			node2 = node1->prev;
			node0 = node0->next;
			while ((node1 != NULL) && (node2 != NULL))
			{
				tmp = node2;
				if (card_key(node2->card) > card_key(node1->card))
				{
					swap_nodes(deck, node1, node2);
				}
				node1 = tmp;
				node2 = tmp->prev;
			}
		}
	}
}
