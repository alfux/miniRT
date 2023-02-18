/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/18 02:33:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_ellbmp(t_vec const *vtx, t_vec const *nml, t_ell const *ell)
{
	t_vec	vbc;
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(ell->bas) == 0.f || !ell->bmp.iid)
		return (*nml);
	vbc = ft_dif_uv(*vtx, ell->pos);
	vbc = ft_nrmlze(ft_setvec(vbc.x * ell->rat.x, vbc.y * ell->rat.y, vbc.z * ell->rat.z));
	vec = ft_nrmlze(ft_multmv(ft_invmat(ell->bas), vbc));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	return (ft_multmv(ft_rotnml(&ell->bas, &vbc, -phi),
			ft_multmv(ell->bas, ft_bmpmap(&ell->bmp, phi * cos(theta),
			phi * sin(theta)))));
}
