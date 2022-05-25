#include <stdio.h>
#include "sort.h"

int	main(void)
{
	int	arr[10] = {9, 1, 7, 0, 4, 6, 5, 3, 2, 8};
	int len = 10;
	int	cnt = 0;
	int newArr[10];
	t_node	*tree;
	
	sort_2el(arr, newArr);
	print_array("sort_2el:", newArr, 2, -1);
	
	sort_3el(arr, newArr);
	print_array("sort_3el:", newArr, 3, -1);

	copy_arr(arr, newArr, len);
	bubble_sort(newArr, len, &cnt);
	print_array("bubble_sort:", newArr, len, cnt);
	
	insert_sort(arr, len, newArr, &cnt);
	print_array("insert_sort:", newArr, len, cnt);

	printf("min_heap: ");
	min_heap(arr);
	printf("\n");

	tree = tree_sort(arr, len);
	printf("tree_sort: ");
	print_inorder(tree);
	printf("\n");
}