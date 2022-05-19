void	sort_3el(int *arr, int *newArr)
{
	if (arr[0] > arr[1])
	{
		if (arr[0] > arr[2])
			newArr[2] = arr[0];
		else
			newArr[1] = arr[0];
	}
	else if (arr[0] < arr[2])
		newArr[0] = arr[0];
	else
		newArr[1] = arr[0];
	
	if (arr[1] > arr[0])
	{
		if (arr[1] > arr[2])
			newArr[2] = arr[1];
		else
			newArr[1] = arr[1];
	}
	else if (arr[1] < arr[2])
		newArr[0] = arr[1];
	else
		newArr[1] = arr[1];

	if (arr[2] > arr[0])
	{
		if (arr[2] > arr[1])
			newArr[2] = arr[2];
		else
			newArr[1] = arr[2];
	}
	else if (arr[2] < arr[1])
		newArr[0] = arr[2];
	else
		newArr[1] = arr[2];
}