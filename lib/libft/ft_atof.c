/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:22:18 by efunes            #+#    #+#             */
/*   Updated: 2022/12/22 17:33:16 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof(const char *str)
{
	size_t	i;
	float	sign;
	float	res;
	float	power;

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
		if (*(str + i) == '.' && !power)
			power++;
		else if (power && *(str + i) != '.')
			power++;
		res = (10 * res + (*(str + i++) - 48));
	}
	while (power--)
		res *= 0.1;
	return (sign * (int)res);
}
