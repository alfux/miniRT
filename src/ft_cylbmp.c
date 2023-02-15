/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:23:23 by alfux             #+#    #+#             */
/*   Updated: 2023/02/14 19:24:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_cylbmp(t_vec const *vtx, t_vec const *nml, t_cyl const *cyl)
{
	t_vec	vbc;
	t_vec	vec;
	double	norm;
	double	theta;
	double	phi;

	if (ft_det3x3(cyl->bas) == 0.f || !cyl->bmp.iid)
		return (*nml);
	vbc = ft_dif_uv(*vtx, cyl->pos);
	norm = ft_norm(vbc);
	vbc = ft_setvec(vbc.x / norm, vbc.y / norm, vbc.z / norm);
	vec = ft_nrmlze(ft_multmv(ft_invmat(cyl->bas), vbc));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	return (ft_multmv(ft_rotnml(&cyl->bas, nml, -M_PI / 2),
			ft_multmv(cyl->bas, ft_bmpmap(&cyl->bmp, norm * vec.z, theta))));
}