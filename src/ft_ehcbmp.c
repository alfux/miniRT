/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ehcbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/27 17:58:52 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_ehcbmp(t_vec const *vtx, t_vec const *nml, t_ehc const *ehc)
{
	t_vec	vec;
	t_vec	basz;
	double	theta;
	double	phi;
	double	lgt;

	if (ft_det3x3(ehc->bns.bmp.bas) == 0.f || !ehc->bns.bmp.map.iid)
		return (*nml);
	vec = ft_dif_uv(*vtx, ft_multmv(ehc->bas, ehc->pos));
	vec = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.bmp.bas), vec));
	basz = ft_setvec(ehc->bns.bmp.bas.top.z, ehc->bns.bmp.bas.mid.z, ehc->bns.bmp.bas.bot.z);;
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	theta = ((theta >= 0) - (theta < 0)) * acos(vec.x / sin(phi));
	if (phi > M_PI / 2)
		phi = (M_PI - phi); 
	lgt = acos(cos(phi) * sqrt(ehc->rat.z)) * ehc->dia / 2;
	return (ft_multmv(ft_rotnml(&ehc->bns.bmp.bas, nml, -acos(ft_scalar(basz, *nml))),
			ft_multmv(ehc->bns.bmp.bas, ft_bmpmap(&ehc->bns.bmp.map,
					&ehc->bns.bmp, lgt * cos(theta), lgt * sin(theta)))));
}
