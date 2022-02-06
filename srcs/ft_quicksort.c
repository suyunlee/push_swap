/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:16:29 by suylee            #+#    #+#             */
/*   Updated: 2021/05/31 13:19:36 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_quicksort(int *array, int start, int end)
{
	int	key;
	int	i;
	int	j;

	i = 0;
	key = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && array[i] <= array[key])
			i++;
		while (j > start && array[j] >= array[key])
			j--;
		if (i > j)
			ft_swap(&array[key], &array[j]);
		else
			ft_swap(&array[i], &array[j]);
	}
	ft_quicksort(array, start, j - 1);
	ft_quicksort(array, j + 1, end);
}

int		get_median(t_node *node, int len)
{
	int		*array;
	int		i;
	t_node	*tmp;
	int		median;

	array = (int*)malloc(sizeof(int) * (len));
	if (!array)
		return (0);
	tmp = node;
	i = 0;
	while (i < len)
	{
		array[i] = node->data;
		node = node->next;
		i++;
	}
	ft_quicksort(array, 0, len - 1);
	median = array[len / 2];
	node = tmp;
	free(array);
	return (median);
}

void	quicksort_a(t_stack *stack, int len)
{
	int	median;
	int	check;
	int	rrn;

	if (a_issort(stack->a))
		return ;
	if (frontsort_a(stack, len))
		return ;
	if (len < 4)
	{
		sort_three_a(stack, len);
		return ;
	}
	median = get_median(stack->a, len);
	check = ft_check(stack->a, len);
	rrn = move_node_a(stack, len, median);
	rr_check(stack, rrn, check, 'a');
	if (len == 5 || len == 6)
	{
		five_sort(stack, len);
		six_sort(stack, len);
		return ;
	}
	return_quicksort(stack, len);
}

void	quicksort_b(t_stack *stack, int len)
{
	int median;
	int check;
	int rrn;

	if (b_issort(stack, len))
		return ;
	if (frontsort_b(stack, len))
		return ;
	if (len < 4)
	{
		sort_three_b(stack, len);
		return ;
	}
	median = get_median(stack->b, len);
	check = ft_check(stack->b, len);
	rrn = move_node_b(stack, len, median);
	rr_check(stack, rrn, check, 'b');
	if (len == 5 || len == 6)
	{
		five_sort(stack, len);
		six_sort(stack, len);
		return ;
	}
	return_quicksort(stack, len);
}
