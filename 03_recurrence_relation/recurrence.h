#ifndef RECURRENCE_H
# define RECURRENCE_H

typedef	struct s_germ
{
	int delay;
	struct s_germ *next;
}	t_germ;

/* 1.recurrence_iter */
int	recurrence_iter(int n, int k);
/* 2.recurrence_dp_bottom_top */
int	recurrence_dp_bottom_top(int n, int k);
/* recurrence_utils */
t_germ	*ft_obj_new(int delay);
t_germ	*ft_obj_last(t_germ *head);
void	ft_obj_pushback(t_germ **head, t_germ *new_node);
int		ft_obj_size(t_germ *head);
void	ft_obj_clear(t_germ **head);
void	arr_print(int *arr, int end);

#endif