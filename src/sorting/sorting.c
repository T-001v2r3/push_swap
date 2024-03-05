/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:15:58 by gperfeit          #+#    #+#             */
/*   Updated: 2023/04/18 14:48:45 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	step_one(t_stack **a, int max)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--max > 0)
	{
		ptr = *a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data->number == INT_MIN && ptr->data->final_index == 0)
				ptr->data->final_index = 1;
			if (ptr->data->number > value && ptr->data->final_index == 0)
			{
				value = ptr->data->number;
				highest = ptr;
				ptr = *a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->data->final_index = max;
	}
}

int	find_maxpoint(t_stack *stack)
{
	int	max;

	max = stack->data->final_index;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->data->final_index > max)
			max = stack->data->final_index;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->prev != NULL)
		stack = stack->prev;
	while (stack->next != NULL)
	{
		if (stack->data->final_index > stack->next->data->final_index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	radix_sort(t_stack **a_stack, t_stack **b_stack, int ac)
{
	t_stack	*lst;
	int		i;
	int		j;
	int		max_b;

	lst = *a_stack;
	max_b = 0;
	while ((find_maxpoint(*a_stack) >> max_b) != 0)
		max_b++;
	i = -1;
	while (++i < max_b)
	{
		j = -1;
		while (++j < ac)
		{
			lst = *a_stack;
			if (((lst->data->final_index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(*a_stack);
		}
		while (*b_stack != NULL)
			pa(a_stack, b_stack);
	}
}
