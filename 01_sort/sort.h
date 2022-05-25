#ifndef SORT_H
# define SORT_H

void	sort_2el(int *arr, int *newArr);
void	sort_3el(int *arr, int *newArr);
void	bubble_sort(int *arr, int len, int *cnt);
void	insert_sort(int *arr, int len, int *newArr, int *cnt);
void	print_array(char *s, int *a, int end, int cnt);

/* 4.heap_sort */
void	min_heap(int *arr);
void	copy_arr(int *arr, int *newArr, int len);

#endif