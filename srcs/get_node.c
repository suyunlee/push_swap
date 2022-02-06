/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:26:18 by suylee            #+#    #+#             */
/*   Updated: 2021/06/01 16:04:50 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_isoverlap(t_node *node, int data)
{
	t_node *tmp;

	tmp = node;
	while (tmp)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_node		*malloc_node(int data)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = 0;
	return (node);
}

static char	**ft_sfree(char **dest)
{
	unsigned int i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

t_node		*get_first_list(char **argv)
{
	char	**split;
	t_node	*list;

	list = 0;
	split = ft_split(argv[1], ' ');
	list = split_node(split, list);
	ft_sfree(split);
	return (list);
}

t_node		*get_node(char **argv)
{
	t_node	*list;
	int		i;
	t_node	*tmp;
	char	**split;

	if (!(list = get_first_list(argv)))
		return (0);
	i = 2;
	tmp = list;
	while (argv[i])
	{
		split = ft_split(argv[i++], ' ');
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = split_node(split, list)))
		{
			ft_sfree(split);
			return (0);
		}
		tmp = tmp->next;
		ft_sfree(split);
	}
	return (list);
}
