#include "search_algos.h"

/**
 * count_outliers - counts nodes that are not leaves or full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: Number of nodes that are not leaves or full
 */
int count_outliers(const binary_tree_t *tree)
{
	int outliers = 0;

	if (tree->left && tree->right)
	{
		outliers += count_outliers(tree->left);
		outliers += count_outliers(tree->right);
	}
	else if ((tree->left && !tree->right) || (!tree->left && tree->right))
	{
		return (1);
	}
	return outliers;
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else if (count_outliers(tree))
		return (0);
	return (1);
}
