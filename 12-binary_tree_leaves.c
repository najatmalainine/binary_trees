#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the binary tree, or 0 if tree is NULL.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!(tree->right) && !(tree->left))
		return (1);

	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
