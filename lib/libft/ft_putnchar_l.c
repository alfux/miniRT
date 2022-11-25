/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:12:33 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 13:14:34 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnchar_l(size_t n, char c, int fd)
{
	size_t	i;

	i = 0;
	while (i < n)
		i += ft_putchar_l(c, fd);
	return (i);
}
