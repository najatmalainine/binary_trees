#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL, else return height.
 */
int height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);

	r_height = tree->right ? 1 + height(tree->right) : 1;
	l_height = tree->left ? 1 + height(tree->left) : 1;

	return ((l_height > r_height) ? l_height : r_height);
}

/**
 * binary_tree_is_parent_full - checks if a node is a parent
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a parent, otherwise 0
 */
int binary_tree_is_parent_full(const binary_tree_t *node)
{
	int parent = 0;

	if (node && node->left && node->right)
		parent = 1;

	return (parent);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{

	if (node != NULL && node->right == NULL && node->left == NULL)
		return (1);

	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if (binary_tree_is_leaf(tree->left) && binary_tree_is_leaf(tree->right))
			return (1);

		if (binary_tree_is_parent_full(tree))
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}
