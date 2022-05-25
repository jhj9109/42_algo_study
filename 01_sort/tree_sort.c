#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

t_node	*new_node(int val)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (ret == NULL)
	{
		perror("Malloc Error\n");
		exit(1);
	}
	ret->val = val;
	ret->cnt = 1;
	ret->l_node = NULL;
	ret->r_node = NULL;
	return (ret);
}

void	add_el(t_node *root, int val)
{
	t_node	*cur;

	cur = root;
	while (1)
	{
		if (val == cur->val)// 1. ==
		{
			cur->cnt = cur->cnt + 1;
			return ;
		}
		if (val < cur->val)// 2. val < node->val => L
		{
			if (cur->l_node == NULL)
			{
				cur->l_node = new_node(val);
				return ;
			}
			cur = cur->l_node;
		}
		else if (val > cur->val)// 3. val > node->val => R
		{
			if (cur->r_node == NULL)
			{
				cur->r_node = new_node(val);
				return;
			}
			cur = cur->r_node;
		}
	}
}

t_node	*tree_sort(int *arr, int len)
{
	t_node	*root;

	root = new_node(arr[0]);	
	for (int i = 1; i < len; i++)
		add_el(root, arr[i]);
	return (root);
}
