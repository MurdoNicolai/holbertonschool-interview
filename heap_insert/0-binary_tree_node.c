#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
*	insert_node - Insert a node in an ordered list
*	@head: the head of the list
*	@number: the number to insert
*	Return: adress of the newly inserted node
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
