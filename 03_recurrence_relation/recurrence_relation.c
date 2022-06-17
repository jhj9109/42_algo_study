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
		printf("recurrence_matrix(%d, %d): %d\n", (int)n, (int)k, recurrence_matrix(n, k));
	}
}