/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:45:13 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/27 17:15:54 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_data(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (*(s + i) == c && *(s + i))
		i++;
	if (!*(s + i))
		return (0);
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			while (*(s + i) == c && *(s + i))
				i++;
			if (*(s + i))
				cnt++;
		}
		else
			i++;
	}
	return (cnt + 1);
}

static size_t	ft_strlen_c(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static char	**verify(char **spl, size_t data)
{
	size_t	i;

	if (!data || *(spl + data - 1))
		return (spl);
	i = 0;
	while (*(spl + i))
		free(*(spl + i++));
	free(spl);
	return ((char **)0);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	data;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return ((char **)0);
	data = ft_data(s, c);
	split = ft_calloc(data + 1, sizeof (char *));
	if (!split)
		return ((char **)0);
	*(split + data) = (char *)0;
	i = 0;
	j = 0;
	while (i < data && !(i > 0 && !*(split + i - 1)))
	{
		while (*(s + j) == c && *(s + j))
			j++;
		len = ft_strlen_c(s + j, c);
		*(split + i) = ft_substr(s, j, len);
		j += len;
		i++;
	}
	return (verify(split, data));
}
