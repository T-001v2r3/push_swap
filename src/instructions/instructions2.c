/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:41:42 by gperfeit          #+#    #+#             */
/*   Updated: 2023/04/16 01:14:13 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	int		tmp;
	int		tmp2;
	t_data	*last;

	if (a != NULL && a->next != NULL)
	{
		tmp = a->data->number;
		tmp2 = a->data->final_index;
		while (a->next != NULL)
		{
			a->data->number = a->next->data->number;
			a->data->final_index = a->next->data->final_index;
			a = a->next;
		}
		last = a->data;
		last->number = tmp;
		last->final_index = tmp2;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	int		tmp;
	int		tmp2;
	t_data	*last;

	if (b != NULL && b->next != NULL)
	{
		tmp = b->data->number;
		tmp2 = b->data->final_index;
		while (b->next != NULL)
		{
			b->data->number = b->next->data->number;
			b->data->final_index = b->next->data->final_index;
			b = b->next;
		}
		last = b->data;
		last->number = tmp;
		last->final_index = tmp2;
	}
	write(1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	int		tmp;
	int		tmp2;
	t_data	*last;

	if (a != NULL && a->next != NULL)
	{
		while (a->next != NULL)
			a = a->next;
		last = a->data;
		tmp = a->data->number;
		tmp2 = a->data->final_index;
		while (a->prev != NULL)
		{
			a->data = a->prev->data;
			a = a->prev;
		}
		a->data = last;
		last->number = tmp;
		last->final_index = tmp2;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	int		tmp;
	int		tmp2;
	t_data	*last;

	if (b != NULL && b->next != NULL)
	{
		while (b->next != NULL)
			b = b->next;
		last = b->data;
		tmp = b->data->number;
		tmp2 = b->data->final_index;
		while (b->prev != NULL)
		{
			b->data = b->prev->data;
			b = b->prev;
		}
		b->data = last;
		last->number = tmp;
		last->final_index = tmp2;
		write(1, "rrb\n", 4);
	}
}
