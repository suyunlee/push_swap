/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:44:32 by suylee            #+#    #+#             */
/*   Updated: 2021/06/01 16:08:11 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_node {
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack {
	t_node*			a;
	t_node*			b;
}					t_stack;

void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				ss(t_stack *stack);
void				rr(t_stack *stack);
void				rrr(t_stack *stack);

void				ft_function(t_stack *stack, char *str);
void				return_quicksort(t_stack *stack, int len);

int					issign(const char c);
int					ft_isintnget(char *str, long *data);
int					ft_check(t_node *node, int len);
void				freenode(t_node *node);

void				three_a(t_stack *stack);
void				sort_three_a(t_stack *stack, int len);
void				three_b(t_stack *stack);
void				else_three_b(t_stack *stack, int *len);
void				sort_three_b(t_stack *stack, int len);

void				rr_check(t_stack *stack, int len, int check, char ab);
int					a_issort(t_node *node);
int					b_issort(t_stack *stack, int len);
int					move_node_a(t_stack *stack, int len, int median);
int					move_node_b(t_stack *stack, int len, int median);

void				ft_swap(int *a, int *b);
void				ft_quicksort(int *array, int start, int end);
int					get_median(t_node *node, int len);
void				quicksort_a(t_stack *stack, int len);
void				quicksort_b(t_stack *stack, int len);

int					ft_isoverlap(t_node *node, int data);
t_node				*malloc_node(int data);
t_node				*split_node(char **split, t_node *list);
t_node				*get_first_list(char **argv);
t_node				*get_node(char **argv);

int					get_three(t_node *node, int len, char ab);
int					frontsort_a(t_stack *stack, int len);
int					frontsort_b(t_stack *stack, int len);

void				six_sort(t_stack *stack, int len);
void				six_sort_small(t_stack *stack);
void				five_sort(t_stack *stack, int len);
void				six_sort_return(t_stack *stack);

#endif
