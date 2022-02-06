/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:29:24 by suylee            #+#    #+#             */
/*   Updated: 2021/06/01 16:01:18 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			issign(const char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

int			ft_isintnget(char *str, long *data)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	if (!(str[i]))
		return (0);
	if (issign(str[i]) != 0)
		sign = issign(str[i++]);
	*data = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		*data = (*data) * 10 + (str[i] - '0');
		if ((*data > 2147483647 && sign == 1)
			|| (*data > 2147483648 && sign == -1))
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	*data = sign * (*data);
	return (1);
}

int			ft_check(t_node *node, int len)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = node;
	while (tmp && i < len)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp)
		return (1);
	else
		return (0);
}

void		freenode(t_node *node)
{
	if (!node)
		return ;
	freenode(node->next);
	free(node);
}

t_node		*split_node(char **split, t_node *list)
{
	int		i;
	long	data;
	t_node	*tmp;
	t_node	*result;

	result = 0;
	i = 0;
	while (split[i])
	{
		if (!(ft_isintnget(split[i++], &data)) || ft_isoverlap(list, data))
		{
			freenode(list);
			freenode(result);
			return (NULL);
		}
		if (!result)
		{
			result = malloc_node(data);
			tmp = result;
			continue ;
		}
		tmp->next = malloc_node(data);
		tmp = tmp->next;
	}
	return (result);
}
