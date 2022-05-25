#include "chess.h"

int **map;
int finish = 0;

static int	_knight_available(int r, int c, int n)
{
	int dr[8] = {-2, -2, 1, -1, 2, 2, 1, -1};
	int dc[8] = {-1, 1, 2, 2, -1, 1, -2, -2};
	int nr;
	int	nc;

	for (int i = 0; i < 8; i++)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		if (is_in(nr, nc, n))
			if (map[nr][nc] == 1)
				return (0);
	}
	return (1);
}
#include <stdio.h>
void	_chess_knight_row_col(int r, int c, int k, int n)
{
	if (k == 0)
	{
		finish = 1;
		print_answer(map, n);
		return ;
	}
	if (!finish && r < n)
	{
		if (_knight_available(r, c, n))
		{
			map[r][c] = 1;
			if (c + 1 == n)
				_chess_knight_row_col(r + 1, 0, k - 1, n);
			else
				_chess_knight_row_col(r, c + 1, k - 1, n);
			map[r][c] = 0;
		}
		if (c + 1 == n)
			_chess_knight_row_col(r + 1, 0, k, n);
		else
			_chess_knight_row_col(r, c + 1, k, n);
	}
}

void	chess_knight(int k, int n)
{
	map = malloc_rect_map(n);
	_chess_knight_row_col(0, 0, k, n);
	finish = 0;
	free_map(map, n);
}
