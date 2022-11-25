/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:06:16 by afuchs            #+#    #+#             */
/*   Updated: 2022/09/05 20:17:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	end_str;

	if (!s)
		return ((char *)0);
	end_str = ft_strlen(s);
	if (start > end_str)
		return (ft_calloc(1, sizeof (char)));
	if (end_str - start < len)
		len = end_str - start;
	sub = ft_calloc(len + 1, sizeof (char));
	if (sub)
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
