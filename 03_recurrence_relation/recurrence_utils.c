#include "recurrence.h"
#include <stdlib.h>
#include <stdio.h>

t_germ	*ft_obj_new(int delay)
{
	t_germ	*ret;

	ret = malloc(sizeof(t_germ));
	if (ret == NULL)
		return (NULL);
	ret->delay = delay;
	return (ret);
}

t_germ	*ft_obj_last(t_germ *head)
{
	t_germ	*cur;

	if (head == NULL)
		return (NULL);
	cur = head;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	ft_obj_pushback(t_germ **head, t_germ *new_node)
{
	t_germ	*last_node;

	last_node = ft_obj_last(*head);
	if (last_node == NULL)
		*head = new_node;
	else
		last_node->next = new_node;
}

int	ft_obj_size(t_germ *head)
{
	t_germ	*cur;
	int		size;

	size = 0;
	cur = head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

void	ft_germ_obj_clear(t_germ **head)
{
	t_germ	*cur;
	t_germ	*temp;

	cur = *head;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*head = NULL;
}

void	arr_print(int *arr, int end)
{
	printf("arr: ");
	for (int i = 0; i < end; i++)
	{
		printf("%d ", arr[i]);
	}
}

static int	_ft_isdigit(const char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoll(const char *str, long long *n)
{
	int	len;

	len = 0;
	*n = 0;
	while (_ft_isdigit(str[len]))
	{
		if (len > 10)
			break ;
		*n = *n * 10 + (str[len] - '0');
		len++;
	}
	if (str[len] != '\0' || len == 0 || UINT32_MAX < *n || *n <= 0)
		return (ERROR);
	return (SUCCESS);
}