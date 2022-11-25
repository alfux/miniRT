/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrh_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:14:01 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 16:53:21 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbrh_l(char up, unsigned int n, int fd, size_t ret)
{
	if (n > 15)
		ret = ft_putnbrh_l(up, n / 16, fd, ret);
	if (n % 16 > 9 && up)
		return (ft_putchar_l(n % 16 + 55, fd) + ret);
	else if (n % 16 > 9)
		return (ft_putchar_l(n % 16 + 87, fd) + ret);
	else
		return (ft_putchar_l(n % 16 + 48, fd) + ret);
}
