#include "sort.h"
#include <stdio.h>

/**
 * swapss - swaps a node with the next <- ->
 * @list: *Pointer to the list
 * @node: node
 * Return: VOID
 */
void swapss(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sort linked list of integers
 * @list: *Pointer to Listr
 * Return: VOID
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swapss(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swapss(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
