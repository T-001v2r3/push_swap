/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:41:55 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/10 00:10:19 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_check_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	check_num(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if ((str[0] == '-') && c == 0)
		{
			c++;
			i++;
		}
		if ((ft_isdigit(str[i]) == 0))
			return (0);
		i++;
	}
	if (ft_check_int(ft_atoilong(str)) == 0)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	j;
	int	converted_input;

	(void)(b);
	converted_input = 0;
	j = 1;
	if (ft_check_doubles(argc, argv) == 0)
		return (0);
	while (argc > 1)
	{
		if (check_num(argv[j]) == 0)
			return (0);
		converted_input = ft_atoi(argv[j]);
		ft_ps_lstadd_back(a, ft_ps_lstnew(converted_input, 0));
		argc--;
		j++;
	}
	return (1);
}

int	validatorhandler(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc <= 2)
	{
		free_stack(a);
		return (0);
	}
	if (check_args(argc, argv, a, b) == 0)
	{
		free_stack(a);
		ft_printf("Error\n");
		return (0);
	}
	step_one(a, argc - 1);
	if (is_sorted(*a) == 1)
	{
		free_stack(a);
		return (0);
	}
	return (1);
}
