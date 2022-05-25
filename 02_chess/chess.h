#ifndef CHESS_H
# define CHESS_H

typedef struct e_node {
	int				val;
	int				cnt;
	struct e_node	*l_node;
	struct e_node	*r_node;
}				t_node;

/* 1.rook */
void	chess_rook(int n);

/* 2.bishop */
void	chess_bishop(int n);

/* 3.queen */
void	chess_queen(int n);

/* 4.knight */
void	chess_knight(int k, int n);

/* 5.closed knight tour */

/* chess_utils */
int		is_in(int r, int c, int n);
void	print_answer(int **arr, int n);
int		diagonal_check(int **arr, int r, int c, int n);
int		cross_check(int **arr, int r, int c, int n);
int		**malloc_rect_map(int n);
void	free_map(int **arr, int end);

#endif
