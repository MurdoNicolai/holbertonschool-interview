#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
*	insert_node - Insert a node in an ordered list
*	@head: the head of the list
*	@number: the number to insert
*	Return: adress of the newly inserted node
**/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *previous_node, *current_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = number;
	if ((*head)->n > new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}
	previous_node = *head;
	current_node = (*head)->next;

	while (1)
	{
		if (current_node->n > new_node->n || current_node == NULL)
		{
			previous_node->next = new_node;
			new_node->next = current_node;
			return (*head);
		}
		previous_node->next = current_node;
		current_node = current_node->next;
	}
}
