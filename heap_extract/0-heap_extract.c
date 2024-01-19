#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Calculate the size of a binary tree
 * @root: Pointer to the root node of the tree
 * Return: Size of the tree
 */
size_t tree_size(const heap_t *root)
{
    if (root == NULL)
        return 0;

    return 1 + tree_size(root->left) + tree_size(root->right);
}

/**
 * get_last_node - Get the last node in the heap
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    if (root == NULL)
        return NULL;

    while (root->left || root->right)
    {
        if (tree_size(root->left) > tree_size(root->right))
            root = root->left;
        else
            root = root->right;
    }

    return root;
}

/**
 * heapify_down - Heapify the heap down from the given node
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;

    if (root->left && root->left->n > largest->n)
        largest = root->left;

    if (root->right && root->right->n > largest->n)
        largest = root->right;

    if (largest != root)
    {
        int temp = root->n;
        root->n = largest->n;
        largest->n = temp;

        heapify_down(largest);
    }
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return 0;

    int extracted_value = (*root)->n;

    heap_t *last_node = get_last_node(*root);

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return extracted_value;
    }

    (*root)->n = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);

    heapify_down(*root);

    return extracted_value;
}
