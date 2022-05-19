#include <stdio.h>
#include "sort.h"

int	sort(void)
{
	int	arr[10] = {1, 0, 3, 2, 5, 4, 6, 7, 8, 9};
	int len = 10;
	int	cnt = 0;
	int newArr[10];
	
	sort_2el(arr, newArr);
	print_array("sort_2el:", newArr, 2, -1);
	
	sort_3el(arr, newArr);
	print_array("sort_3el:", newArr, 3, -1);

	copy_arr(arr, newArr, len);
	bubble_sort(arr, len, &cnt);
	print_array("bubble_sort:", newArr, len, cnt);
	
	insert_sort(arr, len, newArr, &cnt);
	print_array("insert_sort:", newArr, len, cnt);
}