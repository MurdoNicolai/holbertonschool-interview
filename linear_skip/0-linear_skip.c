#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (list == NULL)
		return NULL;
	skiplist_t *next;
	while (list != NULL)
	{
		next = list->express;
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return list;
		// if(next == NULL)
		// {
		// 	printf("Value found between indexes [%ld] and [%ld]", list->index, );
		// 	while (list != NULL)
		// 	{
		// 		list = list->next;
		// 		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		// 		if (list->n == value)
		// 			return list;
		// 	}
		// 	return NULL;
		// }
		if((list->n < value && next->n >= value) || (next->express == NULL))
		{
			printf("Value found between indexes [%ld] and [%ld]\n", list->index, next->index);
			while (list != next->next)
			{
				list = list->next;
				printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
				if (list->n == value)
					return list;
			}
			return NULL;
		}
		list = next;
	}
	return NULL;
}
