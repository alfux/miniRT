/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:45:35 by afuchs            #+#    #+#             */
/*   Updated: 2022/02/23 12:10:26 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (*(s + i))
		if (*(s + i++) == (char)c)
			return ((char *)s + i - 1);
	if (!c)
		return ((char *)s + i);
	return (0x0);
}
