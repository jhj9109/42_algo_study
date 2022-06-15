#include "recurrence.h"
#include <stdlib.h>

t_germ	*ft_obj_new(int delay)
{
	t_germ	*ret;

	ret = malloc(sizeof(t_germ));
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

void	ft_obj_clear(t_germ **head)
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