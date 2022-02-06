/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:24:49 by suylee            #+#    #+#             */
/*   Updated: 2021/05/31 13:25:58 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	t_node *temp;

	if (!stack->b || !stack->b->next)
		return ;
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = stack->b->next;
	temp->prev = stack->b;
	stack->b->next = temp;
	stack->b->prev = NULL;
}

void	pb(t_stack *stack)
{
	t_node *temp;

	if (!stack->a)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = NULL;
	if (stack->a)
		stack->a->prev = NULL;
	if (stack->b)
	{
		temp->next = stack->b;
		stack->b->prev = temp;
	}
	stack->b = temp;
	stack->b->prev = NULL;
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *stack)
{
	t_node *tail;

	if (!(stack->b) || !(stack->b->next))
		return ;
	tail = stack->b->next;
	while (tail->next)
		tail = tail->next;
	tail->next = stack->b;
	stack->b->prev = tail;
	stack->b = stack->b->next;
	stack->b->prev = NULL;
	tail = tail->next;
	tail->next = NULL;
}

void	rrb(t_stack *stack)
{
	t_node *tail;
	t_node *tmp;

	if (!(stack->b) || !(stack->b->next))
		return ;
	tail = stack->b->next;
	while (tail->next && tail->next->next)
		tail = tail->next;
	tmp = tail->next;
	tail->next = NULL;
	tmp->next = stack->b;
	stack->b->prev = tmp;
	stack->b = stack->b->prev;
	stack->b->prev = NULL;
}
