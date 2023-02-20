/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/20 20:20:05 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_ellbmp(t_vec const *vtx, t_vec const *nml, t_ehc const *ell)
{
	t_vec	vbc;
	t_vec	vec;
	double	theta;
	double	phi;
	double	cor;

	if (ft_det3x3(ell->bns.bmp.bas) == 0.f || !ell->bns.bmp.map.iid)
		return (*nml);
	vec = ft_nrmlze(ft_dif_uv(*vtx, ell->pos));
	vbc = ft_nrmlze(ft_setvec(vec.x * ell->rat.x, vec.y * ell->rat.y, vec.z * ell->rat.z));
	cor = ft_norm(vec) / ell->dia;
	vec = ft_nrmlze(ft_multmv(ft_invmat(ell->bas), vec));
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
	return (ft_multmv(ft_rotnml(&ell->bas, &vbc, -phi),
			ft_multmv(ell->bas, ft_bmpmap(&ell->bmp, cor * cos(theta),
			cor * sin(theta)))));
}
