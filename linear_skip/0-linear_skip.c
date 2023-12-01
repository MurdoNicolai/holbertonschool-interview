#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *next;

	if (list == NULL)
		return NULL;

	while (list != NULL)
	{
		next = list->express;
		if(next == NULL)
		{
			next = list;
			while (next->next != NULL)
			{
				next = next->next;
			}

			printf("Value found between indexes [%ld] and [%ld]\n", list->index, next->index);
			while (list != next->next)
			{
				printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
				if (list->n == value)
					return list;
				list = list->next;
			}
			return NULL;
		}
		printf("Value checked at index [%ld] = [%d]\n", next->index, next->n);
		if (list->n == value)
			return list;
		if(list->n < value && next->n >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", list->index, next->index);
			while (list != next->next)
			{
				printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
				if (list->n == value)
					return list;
				list = list->next;
			}
			return NULL;
		}
		list = next;
	}
	return NULL;
}
