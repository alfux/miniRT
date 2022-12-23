/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deadzn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:52:51 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 11:59:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_deadzn(t_2x3 *i, t_vec const *p, float dz)
{
	if (ft_distce(i->top, *p) <= dz)
	{
		if (ft_distce(i->bot, *p) <= dz)
			return (1);
		i->top = i->bot;
	}
	else if (ft_distce(i->bot, *p) <= dz)
		i->bot = i->top;
	return (0);
}
