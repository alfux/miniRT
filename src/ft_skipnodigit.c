/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipnodigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:37:44 by alfux             #+#    #+#             */
/*   Updated: 2022/12/31 19:37:56 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_skipnodigit(char const **str)
{
	while (**str && !ft_isdigit(**str) && **str != '-' && **str != '+')
		(*str)++;
	if (!**str)
		return (1);
	return (0);
}
