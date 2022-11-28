/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setlig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:44:12 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 12:46:00 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_lig	ft_setlig(t_vec pos, float rat, t_rgb col)
{
	t_lig	set;

	set.pos = pos;
	set.rat = rat;
	set.col = col;
	return (set);
}
