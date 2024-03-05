/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:02:12 by gperfeit          #+#    #+#             */
/*   Updated: 2023/03/01 20:02:24 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoilong(const char *s)
{
	int			sign;
	long long	ret;
	int			alreadysign;

	ret = 0;
	sign = 1;
	alreadysign = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (alreadysign == 1)
			return (0);
		alreadysign = 1;
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + *s - '0';
		s++;
	}
	return (sign * (long long)ret);
}
