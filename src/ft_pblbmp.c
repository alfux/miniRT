/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pblbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/03/01 15:23:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_pblbmp(t_vec const *vtx, t_vec const *nml, t_pbol const *pbl)
{
	t_vec	vec;
	t_vec	basz;
	double	theta;
	double	phi;
	double	nrm;

	if (ft_det3x3(pbl->bns.bmp.bas) == 0.f || !pbl->bns.bmp.map.iid)
		return (*nml);
	basz = ft_setvec(pbl->bns.bmp.bas.top.z, pbl->bns.bmp.bas.mid.z,
			pbl->bns.bmp.bas.bot.z);
	vec = ft_dif_uv(*vtx, ft_multmv(pbl->bas, pbl->pos));
	vec = ft_multmv(ft_invmat(pbl->bns.bmp.bas), vec);
	nrm = ft_norm(vec);
	vec = ft_setvec(vec.x / nrm, vec.y / nrm, vec.z / nrm);
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	theta = ((theta >= 0) - (theta < 0)) * acos(vec.x / sin(phi));
	phi = ft_pbllgt(pow(cos(theta), 2) / sqrt(pbl->rat.x) + pow(sin(theta), 2)
			/ sqrt(pbl->rat.y), nrm * sin(phi));
	return (ft_multmv(ft_rotnml(&pbl->bns.bmp.bas, nml,
				-acos(ft_scalar(basz, *nml))), ft_multmv(pbl->bns.bmp.bas,
				ft_bmpmap(&pbl->bns.bmp.map, &pbl->bns.bmp, phi * cos(theta)
					/ sqrt(pbl->rat.x), phi * sin(theta) / sqrt(pbl->rat.y)))));
}
