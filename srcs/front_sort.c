/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:13:00 by suylee            #+#    #+#             */
/*   Updated: 2021/05/31 13:15:56 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_three(t_node *node, int len, char ab)
{
	int		*array;
	int		i;
	int		three;
	t_node	*tmp;

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
	if (ab == 'a')
		three = array[3];
	else
		three = array[len - 4];
	node = tmp;
	free(array);
	return (three);
}

int		frontsort_a(t_stack *stack, int len)
{
	t_node	*tmp;
	int		three;

	tmp = stack->a;
	three = get_three(stack->a, len, 'a');
	if (tmp->data < three && tmp->next->data < three)
	{
		tmp = tmp->next->next;
		while (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		if (!(tmp->next))
		{
			sort_three_a(stack, 3);
			return (1);
		}
	}
	return (0);
}

int		frontsort_b(t_stack *stack, int len)
{
	t_node	*tmp;
	int		back_three;
	int		i;

	back_three = get_three(stack->b, len, 'b');
	if (stack->b->data > back_three && stack->b->next->data > back_three)
	{
		tmp = stack->b->next->next;
		while (tmp->next)
		{
			if (tmp->data < tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		if (!(tmp->next))
		{
			i = -1;
			sort_three_b(stack, 3);
			while (++i < len - 3)
				pa(stack);
			return (1);
		}
	}
	return (0);
}
