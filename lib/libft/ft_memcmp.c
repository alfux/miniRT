/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:31:51 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/24 11:34:34 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n)
		if ((unsigned char)*((char *)s1 + i - 1)
			!= (unsigned char)*((char *)s2 + i - 1))
			return ((unsigned char)*((char *)s1 + i - 1)
				- (unsigned char)*((char *)s2 + i - 1));
	return (0);
}
