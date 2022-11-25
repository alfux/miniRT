/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:54:17 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 16:52:54 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbr_l(int n, int fd, size_t ret)
{
	if (n == -2147483648)
		return (ft_putstr_l("-2147483648", fd));
	else if (n < 0)
	{
		ft_putchar_l('-', fd);
		return (ft_putnbr_l(n * -1, fd, ret) + 1);
	}
	else
	{
		if (n > 9)
			ret = ft_putnbr_l(n / 10, fd, ret);
		return (ft_putchar_l(n % 10 + 48, fd) + ret);
	}
}
