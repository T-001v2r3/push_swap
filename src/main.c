/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:42:08 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/17 20:49:38 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (validatorhandler(argc, argv, &a, &b) == 0)
		return (0);
	else if (argc == 3)
		ra(a);
	else if (argc == 4)
		sortthree(&a);
	else if (argc == 6)
		sortfive(&a, &b);
	else
		radix_sort(&a, &b, argc - 1);
	free_stack(&a);
	free_stack(&b);
}
