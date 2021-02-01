#include "deck.h"

/**
 * swap_nodes - swaps two nodes
 * @node1: node to swap
 * @node2: node to swap
 * @head: pointer to head node
 * Return: void
 */

void swap_nodes(deck_node_t *node1, deck_node_t *node2, deck_node_t **head)
{
	deck_node_t *tmp = node1->prev;

	if (tmp != NULL)
		tmp->next = node2;
	node2->prev = tmp;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		*head = node2;
}

/**
 * len_list - computes lenght of linked list
 * @list: head node of list
 * Return: lenght of the list
 */

int len_list(deck_node_t *list)
{
	int res = 0;

	while (list)
	{
		res++;
		list = list->next;
	}
	return (res);
}

int c_int(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6", "7", 
		"8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(node->card->value, val[i]) == 0)
			return (i + 13 * node->card->kind);
	}
	return (-1);
}

/**
 * cocktail_sort_list - cocktail sorting algo
 * @list: pointer to list to sort
 * Return: void
 */

void sort_deck(deck_node_t **list)
{
	int start = 0, end, flag = 1, counter = 0;
	deck_node_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = *list;
	end = len_list(*list);
	while (flag)
	{
		flag = 0;
		while (counter < end - 1)
		{
			if (c_int(tmp) > c_int(tmp->next))
			{
				flag = 1;
				swap_nodes(tmp, tmp->next, list);
			}
			else
				tmp = tmp->next;
			counter++;
		}
		end--;
		if (flag == 0)
			break;
		flag = 0;
		while (counter > start)
		{
			if (c_int(tmp) < c_int(tmp->prev))
			{
				flag = 1;
				swap_nodes(tmp->prev, tmp, list);
			}
			else
				tmp = tmp->prev;
			counter--;
		}
		start++;
	}
}
