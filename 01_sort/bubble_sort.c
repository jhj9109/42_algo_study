void	bubble_sort(int *arr, int len, int *cnt)
{
	int tmp;

	*cnt = 0;
	for (int j = 0; j < len; j++)
	{
		for (int i = j; i < len - 1; i++)
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
