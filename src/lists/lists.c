/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:41:47 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/17 21:46:57 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_ps_lstnew(int number, int final_index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = (t_data *)malloc(sizeof(t_data));
	if (!node->data)
		return (NULL);
	node->prev = NULL;
	node->data->number = number;
	node->data->final_index = final_index;
	node->next = NULL;
	return (node);
}

t_stack	*ft_ps_lstlast(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_ps_lstadd_back(t_stack **node, t_stack *new)
{
	t_stack	*tmp;

	tmp = *node;
	if (tmp == NULL)
		*node = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	ft_ps_lstadd_front(t_stack **node, t_stack *new)
{
	if (!node || !new)
		return ;
	new->next = *node;
	new->prev = NULL;
	*node = new;
}

int	ft_ps_lstsize(t_stack *node)
{
	int	count;

	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}
