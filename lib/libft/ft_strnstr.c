/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:03:52 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/02 15:01:49 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!*(needle))
		return ((char *)haystack);
	while (i < len && *(haystack + i))
	{
		while (*(haystack + i + j) == *(needle + j) && i + j < len)
			if (!*(needle + ++j))
				return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return ((char *)0);
}
