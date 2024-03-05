/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:41:51 by gperfeit          #+#    #+#             */
/*   Updated: 2023/04/16 01:31:43 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del(void *data)
{
	free(data);
}

void	ft_ps_lstdelone(t_stack *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->data);
	free(node);
}

void	ft_ps_lstclear(t_stack **node, void (*del)(void *))
{
	t_stack	*tmp;

	if (!node || !del)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		ft_ps_lstdelone(*node, del);
		*node = tmp;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->data);
		free(*stack);
		*stack = tmp;
	}
}
