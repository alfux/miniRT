/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/04 12:10:56 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//static int	ft_zone(double rad)
//{
//	if (rad < M_PI / 20)
//		return (1);
//	return (-1);
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
	t_3x3	m;
	double	theta;
	double	phi;

	m = ft_invmat(ft_set3x3(sph->bas.top, sph->bas.mid, sph->bas.bot));
	vec = ft_nrmlze(ft_multmv(m, ft_dif_uv(*vtx, sph->pos)));
	if (fabs(vec.z) == 1)/*(fabs(fabs(vec.z) - 1) < EPSILON)*/
		return (sph->col);
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
