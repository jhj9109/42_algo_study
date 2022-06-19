#include "recurrence.h"
#include <stdio.h>
#include <stdint.h>

int main(int ac, char **av)
{
    long long	n;
    long long	k;

    if (ac != 3)
        printf("Error: only two arguments ok.\n");
    else if (ft_atoll(av[1], &n) == ERROR || ft_atoll(av[2], &k) == ERROR)
		printf("Error: argument is only positive integer ok.\n");
	else
	{
		printf("01_recurrence_iter(%d, %d): %d\n", (int)n, (int)k, recurrence_iter(n, k));
		printf("02_recurrence_dp_bottom_top(%d, %d): %d\n", (int)n, (int)k, recurrence_dp_bottom_top(n, k));
		printf("03_recurrence_recursive(%d, %d): %d\n", (int)n, (int)k, recurrence_recursive(n, k));
		printf("04_recurrence_dp_top_bottom(%d, %d): %d\n", (int)n, (int)k, recurrence_dp_top_bottom(n, k));
		printf("05_recurrence_matrix(%d, %d): %d\n", (int)n, (int)k, recurrence_matrix(n, k));
	}
}