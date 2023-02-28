/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pblrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 03:27:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_rgb	ft_zone(double x, double y, t_pbol const *pbl)
{
	x = x - floor(x / pbl->bns.dam.size) * pbl->bns.dam.size;
	x = (x < pbl->bns.dam.size / 2);
	y = y - floor(y / pbl->bns.dam.size) * pbl->bns.dam.size;
	y = (y < pbl->bns.dam.size / 2);
	if (x == y)
		return (pbl->col);
	return (pbl->bns.dam.col);
}

t_rgb	ft_pblrgb(t_vec const *vtx, t_pbol const *pbl)
{
	t_vec	vec;
	double	theta;
	double	phi;
	double	nrm;

	if (ft_det3x3(pbl->bns.dam.bas) == 0.f)
		return (pbl->col);
	vec = ft_dif_uv(*vtx, ft_multmv(pbl->bas, pbl->pos));
	vec = ft_multmv(ft_invmat(pbl->bns.dam.bas), vec);
	nrm = ft_norm(vec);
	vec = ft_setvec(vec.x / nrm, vec.y / nrm, vec.z / nrm);
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	phi = ft_pbllgt(pow(cos(theta), 2) / sqrt(pbl->rat.x) + pow(sin(theta), 2) / sqrt(pbl->rat.y), nrm * sin(phi));
	return (ft_zone(phi * cos(theta) / sqrt(pbl->rat.x), phi * sin(theta) / sqrt(pbl->rat.y), pbl));
}
