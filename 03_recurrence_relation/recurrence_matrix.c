#include "recurrence.h"
#include <stdio.h>
#include <stdlib.h>

static void	_safe_free(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

typedef struct s_matrix
{
	int	**matrix;
	int	m;
	int	n;
}	t_matrix;

static void	_swap_a_b_matrix(int ***a, int ***b)
{
	int **temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	_swap_a_b_matrix_obj(t_matrix **a, t_matrix **b)
{
	t_matrix	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	_free_matrix(int ***matrix_ptr, int len)
{
	int	**matrix;

	matrix = *matrix_ptr;
	if (matrix)
	{
		for (int i = 0; i < len; i++)
		{
			if (matrix[i])
			{
				free(matrix[i]);
				matrix[i] = NULL;
			}
		}
		free(matrix);
		*matrix_ptr = NULL;
	}
}

static void	_free_matrix_obj(t_matrix **obj_ptr)
{
	t_matrix	*obj;

	obj = *obj_ptr;
	if (obj)
	{
		_free_matrix(&obj->matrix, obj->m);
		*obj_ptr = NULL;
	}
}

static int	**_calloc_matrix(int m, int n)
{
	int	**matrix;
	int	i;

	matrix = calloc((size_t)m, sizeof(void *));
	if (matrix == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < m)
	{
		matrix[i] = calloc((size_t)n, sizeof(int));
		if (matrix[i] == NULL)
		{
			_free_matrix(&matrix, i);
			exit(EXIT_FAILURE);
		}
	}
	return (matrix);
}

t_matrix	*_new_matrix_obj(int m, int n)
{
	t_matrix	*ret;
	int			**matrix;

	ret = calloc((size_t)1, sizeof(t_matrix));
	if (ret == NULL)
		return (NULL);
	ret->m = m;
	ret->n = n;
	ret->matrix = _calloc_matrix(m, n);
	if (ret->matrix == NULL)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

t_matrix	*_make_a_matrix_obj(int n)
{
	t_matrix	*ret;

	ret = _new_matrix_obj(n, n);
	if (ret == NULL)
		return (NULL);
	ret->matrix[0][0] = 1;
	ret->matrix[0][n - 1] = 1;
	for (int r = 1; r < n; r++)
		ret->matrix[r][r - 1] = 1;
	return (ret);
}

t_matrix	*_copy_matrix_obj(t_matrix *origin)
{
	t_matrix	*ret;

	ret = calloc((size_t)1, sizeof(t_matrix));
	if (ret == NULL)
		return (NULL);
	ret->m = origin->m;
	ret->n = origin->n;
	ret->matrix = _calloc_matrix(ret->m, ret->n);
	if (ret->matrix == NULL)
	{
		free(ret);
		return (NULL);
	}
	for (int r = 0; r < ret->m; r++)
		for (int c = 0; c < ret->n; c++)
			ret->matrix[r][c] = origin->matrix[r][c];
	return (ret);
}

static int	_mul_matrix(t_matrix *res, t_matrix *a, t_matrix*b)
{
	if ((res->m != a->m) || \
		(res->n != b->n) || \
		(a->n != b->m))
		return (ERROR);
	for(int r = 0; r < a->m; r++)
	{
		for(int c = 0; c < b->n; c++)
		{
			res->matrix[r][c] = 0;
			for(int i = 0; i < a->n; i++)
				res->matrix[r][c] += a->matrix[r][i] * b->matrix[i][c];
		}
	}
	return (SUCCESS);
}

t_matrix	*_matrix_power(t_matrix *a, int power)
{
	t_matrix	*copied;
	t_matrix	*res;

	if (a->m != a->n || --power <= 0)
		return (NULL);
	copied = _copy_matrix_obj(a);
	res = _new_matrix_obj(a->m, a->n);
	if (copied == NULL || res == NULL)
	{
		_free_matrix_obj(&copied);
		_free_matrix_obj(&res);
		return (NULL);
	}
	while (42)
	{
		if (_mul_matrix(res, copied, a) == ERROR)
		{
			_free_matrix_obj(&copied);
			_free_matrix_obj(&res);
			return (NULL);
		}
		if (--power == 0)
			break ;
		_swap_a_b_matrix_obj(&res, &copied);
	}
	_free_matrix_obj(&copied);
	return (res);
}

t_matrix	*_make_a_n_matrix_obj(int power, int n)
{
	t_matrix	*a;
	t_matrix	*a_n;

	a = _make_a_matrix_obj(n);
	if (a == NULL)
		return (NULL);
	a_n = _matrix_power(a, power);
	_free_matrix_obj(&a);
	return (a_n);
}

t_matrix	*_make_b_matrix_obj(int k, int init_val)
{
	t_matrix	*b;

	b = _new_matrix_obj(k, 1);
	if (b == NULL)
		return (NULL);
	b->matrix[0][0] = init_val;
	return (b);
}

int	recurrence_matrix(int n, int k)
{
	t_matrix	*a_n;
	t_matrix	*b;
	t_matrix	*res;
	int			answer;

	a_n = _make_a_n_matrix_obj(n - 1, k);
	b = _make_b_matrix_obj(k, 1);
	res = _new_matrix_obj(k, 1);
	if (a_n == NULL || b == NULL || res == NULL)
	{
		_free_matrix_obj(&a_n);
		_free_matrix_obj(&b);
		_free_matrix_obj(&res);
		return (ERROR);
	}
	if (_mul_matrix(res, a_n, b) == ERROR)
		return (ERROR);
	answer = res->matrix[0][0];
	_free_matrix_obj(&a_n);
	_free_matrix_obj(&b);
	_free_matrix_obj(&res);
	return (answer);
}
