/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/14 19:25:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_sphbmp(t_vec const *vtx, t_vec const *nml, t_sph const *sph)
{
	t_vec	vbc;
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(sph->bas) == 0.f || !sph->bmp.iid)
		return (*nml);
	vbc = ft_nrmlze(ft_dif_uv(*vtx, sph->pos));
	vec = ft_nrmlze(ft_multmv(ft_invmat(sph->bas), vbc));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	return (ft_multmv(ft_rotnml(&sph->bas, &vbc, -phi),
			ft_multmv(sph->bas, ft_bmpmap(&sph->bmp, phi * cos(theta),
			phi * sin(theta)))));
}
