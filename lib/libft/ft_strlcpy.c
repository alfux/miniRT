/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:02:05 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/24 11:48:36 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i++ + 1 < dstsize && *(src + i - 1))
		*(dst + i - 1) = *(src + i - 1);
	if (dstsize)
		*(dst + i - 1) = '\0';
	while (*(src + i - 1))
		i++;
	return (i - 1);
}
