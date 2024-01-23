#include "deck.h"

/**
 * _strcmp - _strcmp
 * @ss1: ss1
 * @ss2: ss2
 * Return: int
 */
int _strcmp(const char *ss1, const char *ss2)
{
	while (*ss1 && *ss2 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}

	if (*ss1 != *ss2)
		return (*ss1 - *ss2);
	return (0);
}

/**
 * get_value - get_value
 * @card: card
 * Return: char
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
 * insertion_sort_deck_kind - insertion_sort_deck_kind
 * @dk: dk
 * Return: void
 */
void insertion_sort_deck_kind(deck_node_t **dk)
{
	deck_node_t *ir, *in, *tmp;

	for (ir = (*dk)->next; ir != NULL; ir = tmp)
	{
		tmp = ir->next;
		in = ir->prev;
		while (in != NULL && in->card->kind > ir->card->kind)
		{
			in->next = ir->next;
			if (ir->next != NULL)
				ir->next->prev = in;
			ir->prev = in->prev;
			ir->next = in;
			if (in->prev != NULL)
				in->prev->next = ir;
			else
				*dk = ir;
			in->prev = ir;
			in = ir->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - insertion_sort_deck_value
 * @dk: dk
 * Return: void
 */
void insertion_sort_deck_value(deck_node_t **dk)
{
	deck_node_t *ir, *in, *tmp;

	for (ir = (*dk)->next; ir != NULL; ir = tmp)
	{
		tmp = ir->next;
		in = ir->prev;
		while (in != NULL &&
		       in->card->kind == ir->card->kind &&
		       get_value(in) > get_value(ir))
		{
			in->next = ir->next;
			if (ir->next != NULL)
				ir->next->prev = in;
			ir->prev = in->prev;
			ir->next = in;
			if (in->prev != NULL)
				in->prev->next = ir;
			else
				*dk = ir;
			in->prev = ir;
			in = ir->prev;
		}
	}
}

/**
 * sort_deck - sort_deck
 * @deck: deck
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
