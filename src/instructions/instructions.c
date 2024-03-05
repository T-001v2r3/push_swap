/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:41:38 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/17 21:46:23 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	temp;
	int	tmp2;

	if (a != NULL && a->next != NULL)
	{
		temp = a->next->data->number;
		tmp2 = a->next->data->final_index;
		a->next->data->number = a->data->number;
		a->next->data->final_index = a->data->final_index;
		a->data->number = temp;
		a->data->final_index = tmp2;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	int	temp;
	int	tmp2;

	if (b != NULL && b->next != NULL)
	{
		temp = b->next->data->number;
		tmp2 = b->next->data->final_index;
		b->next->data->number = b->data->number;
		b->next->data->final_index = b->data->final_index;
		b->data->number = temp;
		b->data->final_index = tmp2;
		write(1, "sb\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	if (*b != NULL)
		(*b)->prev = *a;
	(*a)->prev = NULL;
	*b = *a;
	*a = tmp;
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	if (*a != NULL)
		(*a)->prev = *b;
	(*b)->prev = NULL;
	*a = *b;
	*b = tmp;
	write(1, "pa\n", 3);
}
