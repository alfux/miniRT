/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/20 19:39:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_zone(double rad)
{
	double	size;

	size = 0.1;
	rad = rad - floor(rad / size) * size;
	if (rad < size / 2)
		return (1);
	return (-1);
}

t_rgb	ft_cylrgb(t_vec const *vtx, t_cyl const *cyl)
{
	t_vec	vec;
	double	z;
	double	theta;

	if (ft_det3x3(cyl->bns.dam.bas) == 0.f)
		return (cyl->col);
	vec = ft_multmv(ft_invmat(cyl->bns.dam.bas), ft_dif_uv(*vtx, cyl->pos));
	z = vec.z;
	vec.z = 0;
	if (vec.y >= 0)
		theta = acos(vec.x / ft_norm(vec));
	else
		theta = -acos(vec.x / ft_norm(vec));
	if (ft_zone(z) * ft_zone(theta) == 1)
		return (cyl->col);
	return (cyl->bns.dam.col);
}
