/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_lo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:14:01 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/16 17:40:27 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_siznbr(t_opt opt, unsigned int n, size_t ret)
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

static size_t	ft_hyp(t_opt opt, unsigned int n, int fd, size_t ret)
{
	size_t	len;

	len = ft_siznbr(opt, n, ret);
	if (opt.plu)
		ret += ft_putchar_l('+', fd);
	else if (opt.spa)
		ret += ft_putchar_l(' ', fd);
	if (opt.per && len < opt.pre)
		ret += ft_putnchar_l(opt.pre - len, '0', fd);
	if (n || !opt.per || opt.pre)
		ret = ft_putnbru_l(n, fd, ret);
	if (ret < opt.wid)
		ret += ft_putnchar_l(opt.wid - ret, ' ', fd);
	return (ret);
}

static size_t	ft_zer(t_opt opt, unsigned int n, int fd, size_t ret)
{
	size_t	len;

	len = ft_siznbr(opt, n, ret);
	if (opt.plu)
		ret += ft_putchar_l('+', fd);
	else if (opt.spa)
		ret += ft_putchar_l(' ', fd);
	if (ret + len < opt.wid)
		ret += ft_putnchar_l(opt.wid - len - ret, '0', fd);
	ret = ft_putnbru_l(n, fd, ret);
	return (ret);
}

static size_t	ft_per(t_opt opt, unsigned int n, int fd, size_t ret)
{
	size_t	len;
	size_t	plu;

	len = ft_siznbr(opt, n, ret);
	plu = 0;
	if (opt.plu || opt.spa)
		plu = 1;
	if (ft_maxof(len, opt.pre) + plu < opt.wid)
		ret += ft_putnchar_l(opt.wid - ft_maxof(len, opt.pre) - plu, ' ', fd);
	if (opt.plu)
		ret += ft_putchar_l('+', fd);
	else if (opt.spa)
		ret += ft_putchar_l(' ', fd);
	if (opt.per && len < opt.pre)
		ret += ft_putnchar_l(opt.pre - len, '0', fd);
	if (n || !opt.per || opt.pre)
		ret = ft_putnbru_l(n, fd, ret);
	return (ret);
}

size_t	ft_putnbru_lo(t_opt opt, unsigned int n, int fd, size_t ret)
{
	if (opt.hyp)
		ret = ft_hyp(opt, n, fd, ret);
	else if (opt.zer && !opt.per)
		ret = ft_zer(opt, n, fd, ret);
	else
		ret = ft_per(opt, n, fd, ret);
	return (ret);
}
