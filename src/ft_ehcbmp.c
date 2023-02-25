/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ehcbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/25 03:59:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_ehcbmp(t_vec const *vtx, t_vec const *nml, t_ehc const *ehc)
{
	t_vec	vec;
	t_vec	nmb;
	double	theta;
	double	phi;
	double	cor;

	if (ft_det3x3(ehc->bns.bmp.bas) == 0.f || !ehc->bns.bmp.map.iid)
		return (*nml);
	vec = ft_dif_uv(*vtx, ft_multmv(ehc->bas, ehc->pos));
	cor = ft_norm(vec);
	vec = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.bmp.bas), vec));
	nmb = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.bmp.bas), *nml));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	theta = ((theta >= 0) - (theta < 0)) * acos(vec.x / sin(phi));
	cor *= pow((phi > M_PI / 2) * (M_PI - phi) + (phi <= M_PI / 2) * phi, 1);
	return (ft_multmv(ft_rotnml(&ehc->bns.bmp.bas, nml, -acos(nmb.z)),
			ft_multmv(ehc->bns.bmp.bas, ft_bmpmap(&ehc->bns.bmp.map,
					&ehc->bns.bmp, cor * cos(theta), cor * sin(theta)))));
}
