/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:37:04 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/15 15:02:19 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_maxof(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	ft_minof(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
