/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/22 00:02:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_sphbmp(t_vec const *vtx, t_vec const *nml, t_sph const *sph)
{
	t_vec	vbc;
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(sph->bns.bmp.bas) == 0.f || !sph->bns.bmp.map.iid)
		return (*nml);
	vbc = ft_nrmlze(ft_dif_uv(*vtx, sph->pos));
	vec = ft_nrmlze(ft_multmv(ft_invmat(sph->bns.bmp.bas), vbc));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	return (ft_multmv(ft_rotnml(&sph->bns.bmp.bas, &vbc, -phi),
			ft_multmv(sph->bns.bmp.bas, ft_bmpmap(&sph->bns.bmp.map, &sph->bns.bmp, phi * cos(theta),
			phi * sin(theta)))));
}
