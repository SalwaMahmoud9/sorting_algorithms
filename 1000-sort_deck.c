#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - _strcmp.
 * @s1: first string.
 * @s2: second string.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - get_value.
 * @card: pointer to card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - insertion_sort_deck_kind.
 * @deck: pointer to head.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *node1, *node2, *temp;

	for (node1 = (*deck)->next; node1 != NULL; node1 = temp)
	{
		temp = node1->next;
		node2 = node1->prev;
		while (node2 != NULL && node2->card->kind > node1->card->kind)
		{
			node2->next = node1->next;
			if (node1->next != NULL)
				node1->next->prev = node2;
			node1->prev = node2->prev;
			node1->next = node2;
			if (node2->prev != NULL)
				node2->prev->next = node1;
			else
				*deck = node1;
			node2->prev = node1;
			node2 = node1->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - insertion_sort_deck_value.
 * @deck: pointer to heads.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *node1, *node2, *temp;

	for (node1 = (*deck)->next; node1 != NULL; node1 = temp)
	{
		temp = node1->next;
		node2 = node1->prev;
		while (node2 != NULL &&
		       node2->card->kind == node1->card->kind &&
		       get_value(node2) > get_value(node1))
		{
			node2->next = node1->next;
			if (node1->next != NULL)
				node1->next->prev = node2;
			node1->prev = node2->prev;
			node1->next = node2;
			if (node2->prev != NULL)
				node2->prev->next = node1;
			else
				*deck = node1;
			node2->prev = node1;
			node2 = node1->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards.
 * @deck: pointer to head.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
