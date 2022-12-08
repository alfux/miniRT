/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shades.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:22:41 by alfux             #+#    #+#             */
/*   Updated: 2022/12/08 12:18:16 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_rgb	ft_shades(t_obj *obj, t_vec vec, t_obj *lig, t_rgb rgb)
{
	t_vec	nor;
	t_vec	dir;
	float	norm;
	float	ind;

	if (!obj)
		return (rgb);
	nor = ft_sum_uv(vec, ft_multiv(-1, ((t_sph *)obj->obj)->pos));
	norm = ft_norm(nor);
	nor = ft_setvec(nor.x / norm, nor.y / norm, nor.z / norm);
	dir = ft_sum_uv(((t_lig *)lig->obj)->pos, ft_multiv(-1, vec));
	norm = ft_norm(dir);
	dir = ft_setvec(dir.x / norm, dir.y / norm, dir.z / norm);
	ind = ft_scalar(nor, dir);
	ind *= ((t_lig *)lig->obj)->rat;
	return (ft_setrgb(rgb.r * ind, rgb.g * ind, rgb.b * ind));
}
