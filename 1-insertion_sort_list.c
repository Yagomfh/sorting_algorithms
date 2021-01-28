#include "sort.h"

/**
  * swap_nodes - swaps two nodes
  * @node: node to swap
  * @head: pointer to head node
  * Return: void
  */

void swap_nodes(listint_t *node, listint_t **head)
{
	listint_t *previous = node->prev, *next_n = node->next;

	if (previous->prev != NULL)
		previous->prev->next = node;
	if (previous->prev == NULL)
		*head = node;
	node->prev = previous->prev;
	node->next = previous;
	previous->prev = node;
	previous->next = next_n;
	if (next_n != NULL)
		next_n->prev = previous;
}

/**
  * insertion_sort_list - insertion sorting algo
  * @list: pointer to list to sort
  * Return: void
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = (*list)->next, *cmp;
	int value;

	while (node)
	{
		value = node->n;
		cmp = node->prev;
		while (value < cmp->n)
		{
			swap_nodes(node, list);
			print_list(*list);
			if (node->prev == NULL)
				break;
			cmp = node->prev;
		}
		node = node->next;
	}
}
