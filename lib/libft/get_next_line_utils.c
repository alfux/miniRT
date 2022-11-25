/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:34:05 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/31 11:33:50 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_eol_in(char *str)
{
	size_t	i;

	i = 0;
	while (i++ < BUFFER_SIZE)
		if (*(str + i - 1) && *(str + i - 1) == '\n')
			return (i);
	return (0);
}

void	*return_and_free(void *ret, void *fr)
{
	free(fr);
	return (ret);
}
