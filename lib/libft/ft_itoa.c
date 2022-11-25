/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:11:20 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/28 13:19:43 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_intmin(void)
{
	char	*str;

	str = ft_calloc(12, sizeof (char));
	if (!str)
		return ((char *)0);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

static size_t	ft_nbsize(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	size_t	size;

	if (n == -2147483648)
		return (ft_intmin());
	neg = 1;
	if (n >= 0)
		neg = 0;
	else
		n *= -1;
	size = ft_nbsize(n);
	str = ft_calloc(size + neg + 1, sizeof (char));
	if (!str)
		return ((char *)0);
	if (neg)
		*str = '-';
	while (size--)
	{
		*(str + size + neg) = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
