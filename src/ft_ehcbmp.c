/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ehcbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 16:58:56 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_ehcbmp(t_vec const *vtx, t_vec const *nml,
		t_ehc const *ehc, double cor)
{
	t_vec	vbc;
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(ehc->bns.bmp.bas) == 0.f || !ehc->bns.bmp.map.iid)
		return (*nml);
	vec = ft_nrmlze(ft_dif_uv(*vtx, ehc->pos));
	vbc = ft_nrmlze(ft_setvec(vec.x * ehc->rat.x, vec.y
				* ehc->rat.y, vec.z * ehc->rat.z));
	cor = ft_norm(vec) / ehc->dia;
	vec = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.bmp.bas), vec));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	if (phi > M_PI / 2)
		cor = (M_PI - phi) * cor;
	else
		cor = phi * cor;
	return (ft_multmv(ft_rotnml(&ehc->bns.bmp.bas, &vbc, -phi),
			ft_multmv(ehc->bns.bmp.bas, ft_bmpmap(&ehc->bns.bmp.map,
					&ehc->bns.bmp, cor * cos(theta), cor * sin(theta)))));
}
