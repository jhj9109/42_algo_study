void	sort_2el(int *arr, int *newArr)
{
	newArr[0] = arr[0] > arr[1] ? arr[1] : arr[0];
	newArr[1] = arr[0] > arr[1] ? arr[0] : arr[1];
}