/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shades.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:22:41 by alfux             #+#    #+#             */
/*   Updated: 2022/12/08 19:16:50 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	ft_shadow(t_win win, t_obj *obj, t_vec vec, t_vec dir)
{
	(void)win;
	(void)obj;
	(void)vec;
	(void)dir;
	return (0);
}

t_rgb	ft_shades(t_win win, t_obj *obj, t_vec vec, t_rgb rgb)
{
	t_vec	dir;
	float	ind;

	if (!obj)
		return (rgb);
	dir = ft_nrmlze(ft_dif_uv(((t_lig *)win.scn.lig->obj)->pos, vec));
	ind = ft_scalar(dir, ft_nrmlze(ft_dif_uv(vec, ((t_sph *)obj->obj)->pos)));
	if (ind < EPSILON)
		return (ft_setrgb(0, 0, 0));
	return (ft_setrgb(rgb.r * ind, rgb.g * ind, rgb.b * ind));
}
