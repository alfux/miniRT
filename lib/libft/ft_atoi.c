/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:01:46 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/23 16:52:46 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
		if (*(str + i++) == '-')
			sign = -1;
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		res = (10 * res + (*(str + i++) - 48));
		if (res > 9223372036854775806 && sign == 1)
			return (-1);
		if (res > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (sign * (int)res);
}
