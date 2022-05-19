#include <stdio.h>

void	print_array(char *s, int *a, int end, int cnt)
{
	printf("%-13s", s);
	for (int i = 0; i < end; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	if (cnt != -1)
		printf("cnt: %d\n", cnt);
	printf("\n");
}
