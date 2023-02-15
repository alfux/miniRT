/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/08 01:32:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//Pokeball
//static int	ft_zone(double rad)
//{
//	if (rad < M_PI / 20)
//		return (-1);
//	return (1);
//}
static int	ft_zone(double rad)
{
	double	size;

	size = M_PI / 10;
	rad = rad - floor(rad / size) * size;
	if (rad < size / 2)
		return (1);
	return (-1);
}

t_rgb	ft_sphrgb(t_vec const *vtx, t_sph const *sph)
{
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(sph->bas) == 0.f)
		return (sph->col);
	vec = ft_nrmlze(ft_multmv(ft_invmat(sph->bas), ft_dif_uv(*vtx, sph->pos)));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	if (ft_zone(phi) * ft_zone(theta) == 1)
		return (sph->col);
	return (sph->co2);
}
