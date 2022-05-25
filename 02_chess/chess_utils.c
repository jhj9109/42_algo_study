#include <stdio.h>
#include <stdlib.h>

static int dr[4] = {1, 1, -1, -1};
static int dc[4] = {1, -1, 1, -1};

int	is_in(int r, int c, int n)
{
	return (0 <= r && r < n && 0 <= c && c < n);
}

int	diagonal_check(int **arr, int r, int c, int n)
{
	int	nr;
	int	nc;

	for (int i = 0; i < 4; i++)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		while (is_in(nr, nc, n))
		{
			if (arr[nr][nc] == 1)
				return (0);
			nr += dr[i];
			nc += dc[i];
		}
	}
	return (1);
}

int	cross_check(int **arr, int r, int c, int n)
{
	for (int i = 0; i < n; i++)
		if (arr[r][i] == 1)
			return (0);
	for (int i = 0; i < n; i++)
		if (arr[i][c] == 1)
			return (0);
	return (1);
}

void	print_answer(int **arr, int n)
{
	int	r;
	int	c;

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
			printf("%d ", arr[r][c]);
		printf("\n");
	}
}

int	**malloc_rect_map(int n)
{
	int i;
	int	**ret;

	ret = calloc(n, sizeof(int *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < n)
	{
		ret[i] = calloc(n, sizeof(int));
		if (!ret[i])
			exit(EXIT_FAILURE);
	}
	return (ret);
}

void	safe_free(void	*target)
{
	if (target)
		free(target);
}

void	free_map(int **arr, int end)
{
	if (arr)
	{
		for (int i = 0; i < end; i++)
			safe_free(arr[i]);
		safe_free(arr);
	}
}