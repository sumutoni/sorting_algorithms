#include "sort.h"

/**
 * check_sorted_l - checks if integers of list are sorted
 * @list: list of integers
 *
 * Return: 1 for sorted, 0 for not sorted
 */
int check_sorted_l(listint_t **list)
{
	listint_t *node;

	node = *list;
	while (node && node->next)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}
/**
 * insertion_sort_list - function that sorts list of integers using insertion
 * algorithm
 * @list: list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp, *next, *prev;

	if (!list || !(*list))
		return;
	node = *list;
	while (!check_sorted_l(list))
	{
		while (node)
		{
			next = node->next;
			while (node->prev)
			{
				if (node->n < node->prev->n)
				{
					temp = node->next;
					prev = node->prev->prev;
					if (temp != NULL)
						node->next->prev = node->prev;
					node->next = node->prev;
					node->prev->next = temp;
					node->prev->prev = node;
					node->prev = prev;
					if (prev != NULL)
						node->prev->next = node;
					if (prev == NULL)
						*list = node;
					print_list(*list);
				}
				else
					break;
			}
			node = next;
		}
	}
}
