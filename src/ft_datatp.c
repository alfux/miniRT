/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datatp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:49:34 by alfux             #+#    #+#             */
/*   Updated: 2023/01/01 12:51:07 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

char	ft_datatp(char const *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == 'v')
	{
		if (ft_isspace(*(line + 1)))
			return (' ');
		return (*(line + 1));
	}
	return (*line);
}
