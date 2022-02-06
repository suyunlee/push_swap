/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:31:53 by suylee            #+#    #+#             */
/*   Updated: 2021/06/01 16:08:38 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_check(t_stack *stack, int len, int check, char ab)
{
	int i;

	i = -1;
	if (check == 1)
	{
		if (ab == 'a')
		{
			while (++i < len)
				ft_function(stack, "rra");
		}
		else
		{
			while (++i < len)
				ft_function(stack, "rrb");
		}
	}
}

int		a_issort(t_node *node)
{
	t_node *tmp;

	tmp = node;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		b_issort(t_stack *stack, int len)
{
	t_node	*tmp;
	int		i;

	tmp = stack->b;
	i = -1;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	if (!(tmp->next))
	{
		while (++i < len)
			pa(stack);
	}
	return (1);
}

int		move_node_a(t_stack *stack, int len, int median)
{
	int pn;
	int i;

	i = -1;
	pn = 0;
	while (++i < len && pn < (len / 2))
	{
		if (stack->a->data < median)
		{
			pb(stack);
			pn++;
		}
		else
			ft_function(stack, "ra");
	}
	return (i - pn);
}

int		move_node_b(t_stack *stack, int len, int median)
{
	int pn;
	int i;

	i = -1;
	pn = 0;
	while (++i < len && pn < (len / 2 + len % 2))
	{
		if (stack->b->data >= median)
		{
			pa(stack);
			pn++;
		}
		else
			ft_function(stack, "rb");
	}
	return (i - pn);
}
