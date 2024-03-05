/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:41:59 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/17 21:49:18 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sortthree(t_stack **a)
{
	int	i;
	int	j;

	i = (*a)->data->final_index;
	j = (*a)->next->data->final_index;
	if ((i < j) && (j < (*a)->next->next->data->final_index))
		return ;
	else if ((i < (*a)->next->next->data->final_index) && (
			(*a)->next->next->data->final_index < j))
	{
		sa(*a);
		ra(*a);
	}
	else if ((j < i) && (i < (*a)->next->next->data->final_index))
		sa(*a);
	else if ((j < (*a)->next->next->data->final_index) && (
			(*a)->next->next->data->final_index < i))
		ra(*a);
	else if (((*a)->next->next->data->final_index < i) && (i < j))
		rra(*a);
	else if (((*a)->next->next->data->final_index < j) && (j < i))
	{
		sa(*a);
		rra(*a);
	}
}

t_stack	*ft_ps_lstcpy(t_stack *lst)
{
	t_stack	*new_lst;
	t_stack	*new_node;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_ps_lstnew(lst->data->number, lst->data->final_index);
		if (!new_node)
			return (NULL);
		ft_ps_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

int	stack_length(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack != NULL)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

void	sortfive(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_length(*a);
	while (len > 3)
	{
		if ((*a)->data->final_index == 0 || (*a)->data->final_index == 1)
		{
			pb(a, b);
			len--;
		}
		else
			ra(*a);
	}
	sortthree(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->data->final_index == 1)
		sa(*a);
}

/*void	print_stacks(t_stack *a, t_stack *b)
{	
	if (b != NULL)
	{
		ft_printf("\n\n\nB: ");
		while (b->prev != NULL)
			b = b->prev;
		while (b->next != NULL)
		{
			ft_printf("number in: ");
			ft_printf("%d \n", b->data->number);
			ft_printf("final index: ");
			ft_printf("%d \n\n", b->data->final_index);
			b = b->next;
		}
		ft_printf("number in: ");
		ft_printf("%d \n", b->data->number);
		ft_printf("final index: ");
		ft_printf("%d \n\n", b->data->final_index);
	}
	if ( a != NULL)
	{
		ft_printf("\n\n\n\nA: ");
		while (a->prev != NULL)
			a = a->prev;
		while (a->next != NULL)
		{
			ft_printf("number in: ");
			ft_printf("%d \n", a->data->number);
			ft_printf("final index: ");
			ft_printf("%d \n\n", a->data->final_index);
			a = a->next;
		}
		ft_printf("number in: ");
		ft_printf("%d\n", a->data->number);
		ft_printf("final index: ");
		ft_printf("%d \n\n", a->data->final_index);
	}
}*/