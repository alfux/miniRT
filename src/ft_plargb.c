/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plargb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/20 19:40:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_zone(double rad)
{
	double	size;

	size = 1;
	rad = rad - floor(rad / size) * size;
	if (rad < size / 2)
		return (1);
	return (-1);
}

t_rgb	ft_plargb(t_vec const *vtx, t_pla const *pla)
{
	t_vec	vec;

	if (ft_det3x3(pla->bns.dam.bas) == 0.f)
		return (pla->col);
	vec = ft_multmv(ft_invmat(pla->bns.dam.bas), ft_dif_uv(*vtx, pla->pos));
	if (ft_zone(vec.x) * ft_zone(vec.y) == 1)
		return (pla->col);
	return (pla->bns.dam.col);
}
