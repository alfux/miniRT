/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/21 23:25:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_zone(double rad, t_ehc const *ehc)
{
	rad = rad - floor(rad / ehc->bns.dam.size) * ehc->bns.dam.size;
	if (rad < ehc->bns.dam.size / 2)
		return (1);
	return (-1);
}

t_rgb	ft_ehcrgb(t_vec const *vtx, t_ehc const *ehc)
{
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(ehc->bns.dam.bas) == 0.f)
		return (ehc->col);
	vec = ft_dif_uv(*vtx, ehc->pos);
	vec = ft_setvec(vec.x * ehc->rat.x,
			vec.y * ehc->rat.y, vec.z * ehc->rat.z);
	vec = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.dam.bas), vec));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	if (ft_zone(phi, ehc) * ft_zone(theta, ehc) == 1)
		return (ehc->col);
	return (ehc->bns.dam.col);
}
