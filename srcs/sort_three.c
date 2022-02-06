/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:37:32 by suylee            #+#    #+#             */
/*   Updated: 2021/06/01 14:40:07 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_a(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->a->next;
	if ((stack->a->data > tmp->data)
		&& (stack->a->data > tmp->next->data))
		ft_function(stack, "ra");
	tmp = stack->a->next;
	if ((stack->a->data < tmp->data)
		&& (tmp->data > tmp->next->data))
		ft_function(stack, "rra");
	if (stack->a->data > stack->a->next->data)
		ft_function(stack, "sa");
	return ;
}

void	sort_three_a(t_stack *stack, int len)
{
	t_node	*tmp;

	if (len < 3)
	{
		if (len == 2 && (stack->a->data > stack->a->next->data)
				&& (stack->b) && (stack->b->data < stack->b->next->data))
			ss(stack);
		if (len == 2 && (stack->a->data > stack->a->next->data))
			ft_function(stack, "sa");
		return ;
	}
	if (!(stack->a->next->next->next))
		three_a(stack);
	tmp = stack->a->next;
	if ((stack->a->data > tmp->data) && (stack->a->data > tmp->next->data))
		ft_function(stack, "sa");
	tmp = stack->a->next;
	if ((stack->a->data < tmp->data) && (tmp->data > tmp->next->data))
	{
		pb(stack);
		ft_function(stack, "sa");
		pa(stack);
	}
	if (stack->a->data > stack->a->next->data)
		ft_function(stack, "sa");
}

void	three_b(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->b->next;
	if ((stack->b->data < tmp->data)
		&& (stack->b->data < tmp->next->data))
		ft_function(stack, "rb");
	tmp = stack->b->next;
	if ((stack->b->data > tmp->data)
		&& (tmp->data < tmp->next->data))
		ft_function(stack, "rrb");
	if (stack->b->data < stack->b->next->data)
		ft_function(stack, "sb");
}

void	else_three_b(t_stack *stack, int *len)
{
	t_node *tmp;

	tmp = stack->b->next;
	if ((stack->b->data < tmp->data)
		&& (stack->b->data < tmp->next->data))
		ft_function(stack, "sb");
	tmp = stack->b->next;
	if ((stack->b->data > tmp->data)
		&& (tmp->data < tmp->next->data)
		&& (stack->b->data > tmp->next->data))
	{
		pa(stack);
		ft_function(stack, "sb");
		*len = *len - 1;
	}
	else if ((stack->b->data > tmp->data) && (tmp->data < tmp->next->data))
	{
		pa(stack);
		ft_function(stack, "sb");
		pb(stack);
	}
	if (stack->b->data < stack->b->next->data)
		ft_function(stack, "sb");
}

void	sort_three_b(t_stack *stack, int len)
{
	t_node	*tmp;
	int		i;

	if (len < 3)
	{
		if (len == 2 && (stack->a->data > stack->a->next->data)
			&& (stack->b->data < stack->b->next->data))
			ss(stack);
		else if (len == 2 && (stack->b->data < stack->b->next->data))
			ft_function(stack, "sb");
	}
	else
	{
		tmp = stack->b->next->next;
		if (!(tmp->next))
			three_b(stack);
		else
			else_three_b(stack, &len);
	}
	i = -1;
	while (++i < len)
		pa(stack);
}
