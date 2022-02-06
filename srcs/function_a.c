/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:20:00 by suylee            #+#    #+#             */
/*   Updated: 2021/05/31 13:21:31 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node *temp;

	if (!stack->a || !stack->a->next)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = stack->a->next;
	temp->prev = stack->a;
	stack->a->next = temp;
	stack->a->prev = NULL;
}

void	pa(t_stack *stack)
{
	t_node *temp;

	if (!stack->b)
		return ;
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = NULL;
	if (stack->b)
		stack->b->prev = NULL;
	if (stack->a)
	{
		temp->next = stack->a;
		stack->a->prev = temp;
	}
	stack->a = temp;
	stack->a->prev = NULL;
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_stack *stack)
{
	t_node *tail;

	if (!(stack->a) || !(stack->a->next))
		return ;
	tail = stack->a->next;
	while (tail->next)
		tail = tail->next;
	tail->next = stack->a;
	stack->a->prev = tail;
	stack->a = stack->a->next;
	stack->a->prev = NULL;
	tail = tail->next;
	tail->next = NULL;
}

void	rra(t_stack *stack)
{
	t_node *tail;
	t_node *tmp;

	if (!(stack->a) || !(stack->a->next))
		return ;
	tail = stack->a->next;
	while (tail->next && tail->next->next)
		tail = tail->next;
	tmp = tail->next;
	tail->next = NULL;
	tmp->next = stack->a;
	stack->a->prev = tmp;
	stack->a = stack->a->prev;
	stack->a->prev = NULL;
}
