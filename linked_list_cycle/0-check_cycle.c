#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
*	insert_node - check if linked list has ciycle
*	@head: the head of the list
*	@number: the number to insert
*	Return: 1 if cycle 0 otherwise
**/
int check_cycle(listint_t *list){
	int i;
	listint_t *head;
	
	if (list == NULL) return 0;
	head = list;
	i = 1000;
	while (i>0){
		i -= 1;
		list = list->next;
		if (list == NULL) return 0;
		if (list == head) return 1;
	}
	return 1;
}
