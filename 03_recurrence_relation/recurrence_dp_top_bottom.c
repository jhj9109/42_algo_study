#include <stdlib.h>

static int	_re_with_dp(int *arr, int n, int k)
{
	if (n == 1)
		return (1);
	else if (n < 1)
		return (0);
	else if (arr[n])
		return (arr[n]);
	arr[n] = _re_with_dp(arr, n - 1, k) + _re_with_dp(arr, n - k, k);
	return (arr[n]); 
}

int	recurrence_dp_top_bottom(int n, int k)
{
	int	*arr;
	int	result;

	arr = calloc(n + 1, sizeof(int));
	if (!arr)
		exit(EXIT_FAILURE);
	result = _re_with_dp(arr, n, k);
	free(arr);
	return (result);
}