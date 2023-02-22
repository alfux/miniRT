/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plargb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/22 01:03:49 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_zone(double rad, t_pla const *pla)
{
	rad = rad - floor(rad / pla->bns.dam.size) * pla->bns.dam.size;
	if (rad < pla->bns.dam.size / 2)
		return (1);
	return (-1);
}

t_rgb	ft_plargb(t_vec const *vtx, t_pla const *pla)
{
	t_vec	vec;

	if (ft_det3x3(pla->bns.dam.bas) == 0.f)
		return (pla->col);
	vec = ft_multmv(ft_invmat(pla->bns.dam.bas), ft_dif_uv(*vtx, pla->pos));
	if (ft_zone(vec.x, pla) * ft_zone(vec.y, pla) == 1)
		return (pla->col);
	return (pla->bns.dam.col);
}
