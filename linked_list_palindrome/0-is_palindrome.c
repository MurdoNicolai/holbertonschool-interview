#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
*	insert_node - Insert a node in an ordered list
*	@head: the head of the list
*	@number: the number to insert
*	Return: adress of the newly inserted node
**/
int is_palindrome(listint_t **head)
{
	int array[200] = {0};
	int i;
	int arraylen;

	i = 1;
	listint_t *pos = *head;
	while (pos) {
		array[i] = pos->n;
		pos = pos->next;
	}
	arraylen = i;
	while (i >= 1) {
		if (array[i] != array[arraylen - i]){
			return(0);
		}
	}
	return(1);
}
