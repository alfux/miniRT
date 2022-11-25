/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrad_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:24:44 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 16:58:40 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_siznbrad(unsigned long long n, size_t ret)
{
	if (!n)
		return (3);
	while (n)
	{
		n /= 16;
		ret++;
	}
	return (ret + 2);
}

size_t	ft_putnbrad_l(unsigned long long n, int fd, size_t ret)
{
	if (n > 15)
		ret = ft_putnbrad_l(n / 16, fd, ret);
	else
		ret += ft_putstr_l("0x", fd);
	if (n % 16 > 9)
		return (ft_putchar_l(n % 16 + 87, fd) + ret);
	else
		return (ft_putchar_l(n % 16 + 48, fd) + ret);
}

size_t	ft_putnbrad_lo(t_opt opt, unsigned long long n, int fd, size_t ret)
{
	if (opt.hyp)
	{
		ret = ft_putnbrad_l(n, fd, ret);
		while (ret++ < opt.wid)
			ft_putchar_fd(' ', fd);
	}
	else
	{
		ret = ft_siznbrad(n, ret);
		while (ret++ < opt.wid)
			ft_putchar_fd(' ', fd);
		ft_putnbrad_l(n, fd, ret);
	}
	return (ret - 1);
}
