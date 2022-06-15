int	recurrence_recursive(int n, int k)
{
	if (n == 1)
		return (1);
	else if (n < 1)
		return (0);
	return (recurrence_recursive(n - 1, k) + recurrence_recursive(n - k, k));
}
