#include "recurrence.h"

int	recurrence_dp_bottom_top(int n, int k)
{
	int	*dp;
	int	answer;

	if (n < 1)
		return (0);
	if (n == 1)
		return (1);
	dp = malloc((n + 1) * sizeof(int));
	dp[0] = 0;
	dp[1] = 1;
	for (int time = 2; time <= n; time++)
	{
		dp[time] = dp[time - 1];
		if (time - k > 0)
			dp[time] += dp[time - k];
	}
	answer = dp[n];
	free(dp);
	return (answer);
}
