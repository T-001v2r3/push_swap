/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:17:54 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 17:09:57 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_data
{
	int		number;
	int		final_index;
}				t_data;

typedef struct s_stack
{
	struct s_stack	*prev;
	t_data			*data;
	struct s_stack	*next;
}				t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	del(void *data);
t_stack	*ft_ps_lstnew(int number, int final_index);
t_stack	*ft_ps_lstlast(t_stack *node);
void	ft_ps_lstadd_back(t_stack **node, t_stack *new);
void	ft_ps_lstadd_front(t_stack **node, t_stack *new);
int		ft_ps_lstsize(t_stack *node);
void	ft_ps_lstdelone(t_stack *node, void (*del)(void *));
void	ft_ps_lstclear(t_stack **node, void (*del)(void *));
void	free_stack(t_stack **stack);
int		ft_check_doubles(int argc, char **argv);
int		check_num(char *str);
int		check_args(int argc, char **argv, t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);
void	step_one(t_stack **a, int max);
int		find_maxpoint(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b, int ac);
void	sortthree(t_stack **a);
void	sortfive(t_stack **a, t_stack **b);
int		validatorhandler(int argc, char **argv, t_stack **a, t_stack **b);
int		stack_length(t_stack *stack);

#endif
