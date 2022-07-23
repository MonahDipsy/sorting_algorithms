#ifndef DECK_H
#define DECK_H

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif

/**
 * enum kind_e - Kinds of cards.
 * @SPADE: The "spade" playing card.
 * @HEART: The "heart" playing card.
 * @CLUB: The "club" playing card.
 * @DIAMOND: The "diamond" playing card.
 */
typedef enum kind_e
{
	/* The "spade" playing card. */
	SPADE = 0,
	/* The "heart" playing card. */
	HEART,
	/* The "club" playing card. */
	CLUB,
	/* The "diamond" playing card. */
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card.
 * @value: Value of the card (From "Ace" to "King").
 * @kind: Kind of the card.
 */
typedef struct card_s
{
	/* Value of the card (From "Ace" to "King"). */
	const char *value;
	/* Kind of the card. */
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a deck of playing cards.
 * @card: Pointer to the card of the node.
 * @prev: Pointer to the previous node of the list.
 * @next: Pointer to the next node of the list.
 */
typedef struct deck_node_s
{
	/* Pointer to the card of the node. */
	const card_t *card;
	/* Pointer to the previous node of the list. */
	struct deck_node_s *prev;
	/* Pointer to the next node of the list. */
	struct deck_node_s *next;
} deck_node_t;

int val_cmp(const char *str1, const char *str2);
int card_key(const card_t *card);
void swap_nodes(deck_node_t **list, deck_node_t *l, deck_node_t *r);
void sort_deck(deck_node_t **deck);

#endif
