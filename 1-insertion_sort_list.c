#include "sort.h"

/**
 * swap_nodes - swap_nodes
 * @ph: ph
 * @node1: node1
 * @node2: node2
 * Return: void
 */
void swap_nodes(listint_t **ph, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*ph = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - insertion_sort_list
 * @list: list.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *in, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		in = i->prev;
		while (in != NULL && i->n < in->n)
		{
			swap_nodes(list, &in, i);
			print_list((const listint_t *)*list);
		}
	}
}
