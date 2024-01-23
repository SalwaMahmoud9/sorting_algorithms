#include "sort.h"

/**
 * swap_list - swap_list
 * @p1: p1
 * @p2: p2
 * @index: index
 * Return: void
 */
void swap_list(listint_t **p1, listint_t **p2, int index)
{
	listint_t *temp1, *temp2;

	temp1 = *p1;
	temp2 = *p2;

	temp1->next = temp2->next;
	temp2->prev = temp1->prev;

	if (temp2->next)
		temp2->next->prev = temp1;

	if (temp1->prev)
		temp1->prev->next = temp2;

	temp1->prev = temp2;
	temp2->next = temp1;

	if (index == 0)
		*p1 = temp2;
	else
		*p2 = temp1;
}

/**
 * increase_sort - increase_sort
 * @p: p
 * @l: l
 * @list: list
 * Return: void
 */
void increase_sort(listint_t **p, listint_t **l, listint_t **list)
{
	listint_t *temp;

	temp = *p;

	while (temp != *l && temp->next != *l)
	{
		if (temp->n > temp->next->n)
		{
			swap_list(&temp, &(temp->next), 0);
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		temp = temp->next;
	}

	*l = temp;
	*p = temp;
}

/**
 * decrease_sort - decrease_sort
 * @p: p
 * @l: l
 * @list: list
 * Return: void
 */
void decrease_sort(listint_t **p, listint_t **l, listint_t **list)
{
	listint_t *temp;

	temp = *p;

	while (temp != *l && temp->prev != *l)
	{
		if (temp->n < temp->prev->n)
		{
			swap_list(&(temp->prev), &temp, 1);
			if (temp->prev->prev == NULL)
				*list = temp->prev;
			print_list(*list);
		}
		temp = temp->prev;
	}

	*l = temp;
	*p = temp;
}

/**
 * cocktail_sort_list - cocktail_sort_list
 * @list: list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *l1, *l2, *p;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	l1 = l2 = NULL;
	p = *list;

	do {
		increase_sort(&p, &l1, list);
		decrease_sort(&p, &l2, list);
	} while (l1 != l2);
}
