#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

static void	_swap_el(int *newArr, int a, int b)
{
	int	temp;

	temp = newArr[a];
	newArr[a] = newArr[b];
	newArr[b] = temp;
}

static void	_add_el(int val, int pos, int *newArr)
{
	int tmp;

	newArr[pos] = val;
	while (pos != 1)
	{
		if (newArr[pos] < newArr[pos / 2])
		{
			tmp = newArr[pos];
			newArr[pos] = newArr[pos / 2];
			newArr[pos / 2] = tmp;

			pos = pos / 2;
		}
		else
			return ;
	}
	return ;
}

static int	_pop_el(int *newArr, int len)
{
	int	ret;
	int	pos;
	int	next_pos;
	int	left_child;
	int	right_child;

	ret = newArr[1];
	if (len == 1)
		return (ret);
	newArr[1] = newArr[len];//11
	pos = 1;
	while(pos * 2 <= len)
	{
		next_pos = pos;
		left_child = pos * 2;
		right_child = pos * 2 + 1;
		if (newArr[next_pos] > newArr[left_child])
			next_pos = left_child;
		if (right_child <= len && newArr[next_pos] > newArr[right_child])
			next_pos = right_child;	
		if (next_pos == pos)
			break ;
		_swap_el(newArr, pos, next_pos);
		pos = next_pos;
	}
	return (ret);
}

void	min_heap(int *arr)
{
	int newArr[11];

	for (int i = 1; i <= 10; i++)
		_add_el(arr[i - 1], i, newArr);
	for (int len = 10; len > 0; len--)
		printf("%d ", _pop_el(newArr, len));
}
