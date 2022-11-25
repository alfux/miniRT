/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:14:01 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/16 17:40:19 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_siznbr(t_opt opt, int n, size_t ret)
{
	if (!n && opt.per && !opt.pre)
		return (0);
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static size_t	ft_hyp(t_opt opt, int n, int fd, size_t ret)
{
	size_t	len;
	int		sign;

	len = ft_siznbr(opt, n, ret);
	sign = 1;
	if (opt.plu && n >= 0)
		ret += ft_putchar_l('+', fd);
	else if (opt.spa && n >= 0)
		ret += ft_putchar_l(' ', fd);
	else if (n < 0)
	{
		ret += ft_putchar_l('-', fd);
		sign = -1;
	}
	if (opt.per && len < opt.pre)
		ret += ft_putnchar_l(opt.pre - len, '0', fd);
	if (n || !opt.per || opt.pre)
		ret = ft_putnbru_l(sign * n, fd, ret);
	if (ret < opt.wid)
		ret += ft_putnchar_l(opt.wid - ret, ' ', fd);
	return (ret);
}

static size_t	ft_zer(t_opt opt, int n, int fd, size_t ret)
{
	size_t	len;
	int		sign;

	len = ft_siznbr(opt, n, ret);
	sign = 1;
	if (opt.plu && n >= 0)
		ret += ft_putchar_l('+', fd);
	else if (opt.spa && n >= 0)
		ret += ft_putchar_l(' ', fd);
	else if (n < 0)
	{
		ret += ft_putchar_l('-', fd);
		sign = -1;
	}
	if (ret + len < opt.wid)
		ret += ft_putnchar_l(opt.wid - len - ret, '0', fd);
	ret = ft_putnbru_l(sign * n, fd, ret);
	return (ret);
}

static size_t	ft_per(t_opt opt, int n, int fd, size_t ret)
{
	size_t	len;
	size_t	plu;
	size_t	sign;

	len = ft_siznbr(opt, n, ret);
	plu = 0;
	sign = 1;
	if (opt.plu || opt.spa || n < 0)
		plu = 1;
	if (ft_maxof(len, opt.pre) + plu < opt.wid)
		ret += ft_putnchar_l(opt.wid - ft_maxof(len, opt.pre) - plu, ' ', fd);
	if (opt.plu && n >= 0)
		ret += ft_putchar_l('+', fd);
	else if (opt.spa && n >= 0)
		ret += ft_putchar_l(' ', fd);
	else if (n < 0)
	{
		ret += ft_putchar_l('-', fd);
		sign = -1;
	}
	if (opt.per && len < opt.pre)
		ret += ft_putnchar_l(opt.pre - len, '0', fd);
	if (n || !opt.per || opt.pre)
		ret = ft_putnbru_l(sign * n, fd, ret);
	return (ret);
}

size_t	ft_putnbr_lo(t_opt opt, int n, int fd, size_t ret)
{
	if (opt.hyp)
		ret = ft_hyp(opt, n, fd, ret);
	else if (opt.zer && !opt.per)
		ret = ft_zer(opt, n, fd, ret);
	else
		ret = ft_per(opt, n, fd, ret);
	return (ret);
}
