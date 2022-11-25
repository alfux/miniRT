/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:07:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 16:51:18 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbru_l(unsigned int n, int fd, size_t ret)
{
	if (n > 9)
		ret = (ft_putnbru_l(n / 10, fd, ret));
	return (ft_putchar_l(n % 10 + 48, fd) + ret);
}
