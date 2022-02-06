/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:55:23 by suylee            #+#    #+#             */
/*   Updated: 2021/06/01 16:17:55 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		len;
	t_node	*tmp;

	if (argc < 2)
		return (0);
	len = 0;
	stack = (t_stack){ get_node(argv), 0 };
	tmp = stack.a;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (!stack.a)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	quicksort_a(&stack, len);
	freenode(stack.a);
	freenode(stack.b);
	return (0);
}
