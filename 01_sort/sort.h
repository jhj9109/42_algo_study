#ifndef SORT_H
# define SORT_H

typedef struct e_node {
	int				val;
	int				cnt;
	struct e_node	*l_node;
	struct e_node	*r_node;
}				t_node;

/* 1.sort_by_conditions */
void	sort_2el(int *arr, int *newArr);
void	sort_3el(int *arr, int *newArr);

/* 2.bubble_sort */
void	bubble_sort(int *arr, int len, int *cnt);

/* 3.insert_sort */
void	insert_sort(int *arr, int len, int *newArr, int *cnt);

void	print_array(char *s, int *a, int end, int cnt);

/* 4.heap_sort */
void	min_heap(int *arr);
void	copy_arr(int *arr, int *newArr, int len);

/* 5.tree_sort */
t_node	*tree_sort(int *arr, int len);
void	print_inorder(t_node *node);

#endif