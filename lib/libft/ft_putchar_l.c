/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:41:13 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/09 17:16:11 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putchar_l(char c, int fd)
{
	if (write(fd, &c, 1) != -1)
		return (1);
	return (0);
}

size_t	ft_putchar_lo(t_opt opt, char c, int fd)
{
	size_t	ret;

	if (opt.wid <= 1)
		return (ft_putchar_l(c, fd));
	else
	{
		ret = 0;
		if (opt.hyp)
		{
			ret += ft_putchar_l(c, fd);
			while (ret < opt.wid)
				ret += ft_putchar_l(' ', fd);
			return (ret);
		}
		else
		{
			while (ret + 1 < opt.wid)
				ret += ft_putchar_l(' ', fd);
			return (ret + ft_putchar_l(c, fd));
		}
	}
}
