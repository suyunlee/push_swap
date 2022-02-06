/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:23:05 by suylee            #+#    #+#             */
/*   Updated: 2021/05/31 13:24:17 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr_fd("rrr\n", 1);
}

void	ft_function(t_stack *stack, char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		sa(stack);
	if (str[0] == 's' && str[1] == 'b')
		sb(stack);
	if (str[0] == 'r' && str[1] == 'a')
		ra(stack);
	if (str[0] == 'r' && str[1] == 'b')
		rb(stack);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(stack);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(stack);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}

void	return_quicksort(t_stack *stack, int len)
{
	quicksort_a(stack, (len / 2) + (len % 2));
	quicksort_b(stack, len / 2);
}
