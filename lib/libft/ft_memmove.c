/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:41:33 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/24 11:24:23 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src < dst)
		while (n-- > 0)
			*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
