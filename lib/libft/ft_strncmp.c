/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:24:12 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/01 17:11:18 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while ((unsigned char)*(s1 + i) == (unsigned char)*(s2 + i) && *(s1 + i)
		&& i < n - 1)
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
