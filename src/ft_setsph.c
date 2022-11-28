/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:46:58 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 13:00:29 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_sph	ft_setsph(float dia, t_vec pos, t_rgb col)
{
	t_sph	set;

	set.dia = dia;
	set.pos = pos;
	set.col = col;
	return (set);
}
