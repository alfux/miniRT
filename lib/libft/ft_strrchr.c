/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:11:04 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/23 12:19:57 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*buf;

	i = 0;
	buf = 0x0;
	while (*(s + i))
		if (*(s + i++) == (char)c)
			buf = (char *)s + i - 1;
	if (!c)
		return ((char *)s + i);
	return (buf);
}
