#include "recurrence.h"
/*
	germ 객체 하나를 구조체로 표현.
	매 time germ 하나가 증폭할 수 있는 상태인지 업데이트
	증폭할 수 있는 germ이면 germ 객체(구조체) 생성하여 붙이기.
*/
int	recurrence_iter(int n, int k)
{
	t_germ	*head;
	t_germ	*cur;
	int		answer;

	if (n < 1)
		return (0);
	head = ft_obj_new(k);
	for (int time = 1; time <= n; time++)
	{
		cur = head;
		while (cur)
		{
			if (cur->delay)
				cur->delay--;
			else
				ft_obj_pushback(&head, ft_obj_new(k));
			cur = cur->next;
		}
	}
	answer = ft_obj_size(head);
	ft_obj_clear(&head);
	return (answer);
}
