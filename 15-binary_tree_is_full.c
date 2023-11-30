#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: tree root
 * Return: 1 if tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If the tree is a leaf, it is full by definition */
	if (!(tree->right) && !(tree->left))
		return (1);

	/* If the tree has one child, it is not full */
	if ((!(tree->right) && (tree->left)) ||
		((tree->right) && !(tree->left)))
		return (0);

	/* Recursively check if both subtrees are full */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

