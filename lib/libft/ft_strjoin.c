/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:22:55 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/02 15:15:24 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*cat;
	size_t	size;

	if (!s1 || !s2)
		return ((char *)0);
	size = ft_strlen(s1) + ft_strlen(s2);
	cat = ft_calloc(size + 1, sizeof (char));
	if (!cat)
		return ((char *)0);
	ft_strlcpy(cat, s1, size + 1);
	ft_strlcat(cat, s2, size + 1);
	return (cat);
}
