/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 15:47:47 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_zone(double rad, t_sph const *sph)
{
	rad = rad - floor(rad / sph->bns.dam.size) * sph->bns.dam.size;
	if (rad < sph->bns.dam.size / 2)
		return (1);
	return (-1);
}

t_rgb	ft_sphrgb(t_vec const *vtx, t_sph const *sph)
{
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(sph->bns.dam.bas) == 0.f)
		return (sph->col);
	vec = ft_nrmlze(ft_multmv(ft_invmat(sph->bns.dam.bas),
				ft_dif_uv(*vtx, sph->pos)));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	if (ft_zone(phi, sph) * ft_zone(theta, sph) == 1)
		return (sph->col);
	return (sph->bns.dam.col);
}
