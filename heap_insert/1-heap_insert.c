#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
*	insert_node - Insert a node in an ordered list
*	@root: the root of the list
*	@number: the number to insert
*	Return: adress of the newly inserted node
**/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current_node;

	new_node = malloc(sizeof(heap_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = NULL;
	if ((*root) == NULL)
	{
		*root = new_node;
		return (*root);
	}
	if ((*root)->n < new_node->n)
	{
		new_node->left = *root;
		new_node->left->parent = new_node;
		*root = new_node;
		return (*root);
	}
	current_node = (*root);
	while (1)
	{
		if (current_node->left == NULL){
			current_node->left = new_node;
			new_node->parent = current_node;
			return (*root);
		}
		if (current_node->left->n < new_node->n)
		{
			new_node->left = current_node->left;
			new_node->parent = current_node;
			current_node->left = new_node;
			new_node->left->parent = new_node;
			return (*root);
		}
		current_node = current_node->left;
	}
}
