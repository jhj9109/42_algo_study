#include <stdio.h>
#include "sort.h"

void	print_inorder(t_node *node)
{
	if (node->l_node)
		print_inorder(node->l_node);
	for (int i = 0; i < node->cnt; i++)
		printf("%d ", node->val);
	if (node->r_node)
		print_inorder(node->r_node);
}
