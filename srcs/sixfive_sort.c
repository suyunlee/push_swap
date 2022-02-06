/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixfive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:41:34 by suylee            #+#    #+#             */
/*   Updated: 2021/05/31 19:04:37 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_stack *stack, int len)
{
	t_node *tmp;

	if (len == 5)
	{
		tmp = stack->a->next;
		if ((stack->a->data > tmp->data) && (stack->a->data > tmp->next->data)
			&& (stack->b->data < stack->b->next->data))
			ss(stack);
		sort_three_a(stack, 3);
		sort_three_b(stack, 2);
	}
}

void	six_sort(t_stack *stack, int len)
{
	t_node *tmp;

	if (len == 6)
	{
		tmp = stack->a->next->next;
		if (!(tmp->next))
			three_a(stack);
		tmp = stack->b->next->next;
		if (!(tmp->next))
			three_b(stack);
		six_sort_small(stack);
		six_sort_return(stack);
		six_sort_small(stack);
		sort_three_a(stack, 3);
		sort_three_b(stack, 3);
	}
}

void	six_sort_return(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->a->next;
	if (stack->a->data > tmp->data && stack->a->data > tmp->next->data)
		ft_function(stack, "sa");
	six_sort_small(stack);
	tmp = stack->b->next;
	if (stack->b->data < tmp->data && stack->b->data < tmp->next->data)
		ft_function(stack, "sb");
	six_sort_small(stack);
	tmp = stack->a->next;
	if (stack->b->data < tmp->data && tmp->data > tmp->next->data)
	{
		ft_function(stack, "ra");
		ft_function(stack, "sa");
		ft_function(stack, "rra");
	}
	six_sort_small(stack);
	tmp = stack->b->next;
	if (stack->b->data > tmp->data && tmp->data < tmp->next->data)
	{
		ft_function(stack, "rb");
		ft_function(stack, "sb");
		ft_function(stack, "rrb");
	}
}

void	six_sort_small(t_stack *stack)
{
	t_node *tmp;
	t_node *tmp_two;

	tmp = stack->a->next;
	tmp_two = stack->b->next;
	if ((stack->a->data > tmp->data) && (stack->a->data > tmp->next->data)
		&& ((stack->b->data < tmp_two->data)
		&& (stack->b->data < tmp_two->next->data)))
		ss(stack);
	tmp = stack->a->next;
	tmp_two = stack->b->next;
	if (((stack->a->data < tmp->data) && (tmp->data > tmp->next->data))
		&& ((stack->b->data > tmp_two->data)
		&& (tmp_two->data < tmp_two->next->data)))
	{
		rr(stack);
		ss(stack);
		rrr(stack);
	}
	if (stack->a->data > stack->a->next->data
		&& stack->b->data < stack->b->next->data)
		ss(stack);
}
