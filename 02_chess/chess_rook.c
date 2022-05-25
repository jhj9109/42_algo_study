#include "chess.h"
#include <stdio.h>

static int	**map;
static int finish = 0;

/* 방법1 */
static int	_rook_available(int r, int c, int n)
{
	return (cross_check(map, r, c, n));
}

static void	_chess_rook_row_col(int r, int c, int n)
{
	if (finish)
		return ;
	if (r == n)
	{
		finish = 1;
		print_answer(map, n);
		return ;
	}
	if (c == n)
	{
		_chess_rook_row_col(r + 1, 0, n);
		return ;
	}
	if (_rook_available(r, c, n))
	{
		map[r][c] = 1;
		_chess_rook_row_col(r, c + 1, n);
		map[r][c] = 0;
	}
	_chess_rook_row_col(r, c + 1, n);
}

/* 방법2 */
static void	_chess_rook_row(int r, int n)
{
	if (finish)
		return ;
	if (r == n)
	{
		finish = 1;
		print_answer(map, n);
		return ;
	}
	for (int c = 0; c < n; c++)
	{
		if (_rook_available(r, c, n))
		{	
			map[r][c] = 1;
			_chess_rook_row(r + 1, n);
			map[r][c] = 0;
		}
	}
}

void	chess_rook(int n)
{
	map = malloc_rect_map(n);
	printf("method1\n");
	_chess_rook_row(0, n);
	finish = 0;
	free_map(map, n);
	
	map = malloc_rect_map(n);
	printf("method2\n");
	_chess_rook_row_col(0, 0, n);
	finish = 0;
	free_map(map, n);
}
