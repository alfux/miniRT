/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:22:18 by efunes            #+#    #+#             */
/*   Updated: 2022/12/24 13:11:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

float	ft_atof(const char *str)
{
	size_t	i;
	float	sign;
	float	res;
	int		power;

	i = 0;
	sign = 1;
	res = 0;
	power = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
		if (*(str + i++) == '-')
			sign = -1;
	while ((*(str + i) >= 48 && *(str + i) <= 57) || *(str + i) == '.')
	{
		if ((*(str + i) == '.' && !power) || (power && *(str + i) != '.'))
			power++;
		if (*(str + i++) != '.')
			res = (10 * res + (*(str + i - 1) - 48));
	}
	while (--power > 0)
		res *= 0.1;
	return (sign * res);
}
