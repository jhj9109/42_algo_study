static int	_add2(int *newArr, int len, int el, int *cnt)
{
	if (len == 0 || el > newArr[len - 1])
		newArr[len] = el;
	else
		for (int i = 0; i < len; i++)
		{
			*cnt = *cnt + 1;
			if (el < newArr[i])
			{
				for (int j = len - 1; j >= i; j--)
					newArr[j + 1] = newArr[j];
				newArr[i] = el;
				
			}
		}
	return (len + 1);
}

static int	_add1(int *newArr, int len, int el, int *cnt)
{
	int i;

	i = 0;
	for (; i < len; i++)
	{
		*cnt = *cnt + 1;
		if (el < newArr[i])
			break;
	}
	for (int j = len - 1; j >= i; j--)
		newArr[j + 1] = newArr[j];
	newArr[i] = el;
	return (len + 1);
}

void	insert_sort(int *arr, int len, int *newArr, int *cnt)
{
	*cnt = 0;
	int	newArr_len = 0;
	for (int i = 0; i < len; i++)
		newArr_len = _add1(newArr, newArr_len, arr[i], cnt);
		// newArr_len = add2(newArr, newArr_len, arr[i]);
}
