/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/18 02:07:22 by alfux            ###   ########.fr       */
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

t_rgb	ft_ellrgb(t_vec const *vtx, t_ell const *ell)
{
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(ell->bas) == 0.f)
		return (ell->col);
	vec = ft_dif_uv(*vtx, ell->pos);
	vec = ft_setvec(vec.x * ell->rat.x,
			vec.y * ell->rat.y, vec.z * ell->rat.z);
	vec = ft_nrmlze(ft_multmv(ft_invmat(ell->bas), vec));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	if (ft_zone(phi) * ft_zone(theta) == 1)
		return (ell->col);
	return (ell->co2);
}
