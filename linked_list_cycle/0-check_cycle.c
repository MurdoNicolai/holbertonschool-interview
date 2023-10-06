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
	listint_t *head;
	head = list;
	while (1){
		list = list->next;
		if (list == NULL) return 0;
		if (list == head) return 1;
	}
}
