#include "chess.h"

static int	**map;
static int finish = 0;

static int	_queen_available(int r, int c, int n)
{
	return (cross_check(map, r, c, n) && diagonal_check(map, r, c, n));
}

static void	_chess_queen_row(int r, int n)
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
		if (_queen_available(r, c, n))
		{
			map[r][c] = 1;
			_chess_queen_row(r + 1, n);
			map[r][c] = 0;
		}
	}
}

void	chess_queen(int n)
{
	map = malloc_rect_map(n);
	_chess_queen_row(0, n);
	finish = 0;
	free_map(map, n);
}
