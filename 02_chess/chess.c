#include "chess.h"
#include <stdio.h>

int	main(void)
{
	int	n;
	int	k;

	n = 6;
	k = 19;
	printf("%15s\n", "chess_rook");
	chess_rook(n);

	printf("%15s\n", "chess_bishop");
	chess_bishop(n);

	printf("%15s\n", "chess_queen");
	chess_queen(n);

	printf("%15s\n", "chess_knight");
	chess_knight(k, n);
}