#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/* Our own functions */
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root = NULL;

	root = binary_tree_node(NULL, 180);
	if (!root)
	{
		printf("binary_tree_node returned NULL\n");
		return (1);
	}
	printf("Parent:%p\n", (void *)(root->parent));
	printf("Left:%p\n", (void *)(root->left));
	printf("Right:%p\n", (void *)(root->right));
	binary_tree_print(root);
	_binary_tree_delete(root);
	return (0);
}
