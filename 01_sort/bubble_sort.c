void	bubble_sort(int *arr, int len, int *cnt)
{
	int tmp;

	*cnt = 0;
	for (int end = len - 1; end > 0; end--)
	{
		for (int i = 0; i < end; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			*cnt = *cnt + 1;
		}
	}
}
