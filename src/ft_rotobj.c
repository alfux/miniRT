/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:29:22 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 15:18:33 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_3x3	ft_getmat(double tta, char axi, t_cam const *cam)
{
	t_3x3	rot;
	t_3x3	bas;

	if (axi == 'x')
		rot = ft_set3x3(ft_setvec(1, 0, 0), ft_setvec(0, cos(tta), sin(tta)),
				ft_setvec(0, -sin(tta), cos(tta))); 
	else if (axi == 'y')
		rot = ft_set3x3(ft_setvec(cos(tta), 0, -sin(tta)), ft_setvec(0, 1, 0),
				ft_setvec(sin(tta), 0, cos(tta)));
	else if (axi == 'z')
		rot = ft_set3x3(ft_setvec(cos(tta), sin(tta), 0),
				ft_setvec(-sin(tta), cos(tta), 0), ft_setvec(0, 0, 1));
	else
		return (ft_set3x3(ft_setvec(1, 0, 0), ft_setvec(0, 1, 0),
			ft_setvec(0, 0, 1)));
	bas = ft_set3x3(cam->hor, cam->ver, cam->dir);
	return (ft_multmm(ft_multmm(bas, rot), ft_invmat(bas)));
}

void	ft_rotobj(t_obj const *obj, double tta, char axi, t_cam const *cam)
{
	if (obj->type == 'S')
		ft_rotsph(obj->obj, ft_getmat(tta, axi, cam));
	else if (obj->type == 'P')
		ft_rotpla(obj->obj, ft_getmat(tta, axi, cam));
	else if (obj->type == 'C')
		ft_rotcyl(obj->obj, ft_getmat(tta, axi, cam));
	else if (obj->type == 'p')
		ft_rotpbl(obj->obj, ft_getmat(tta, axi, cam));
	else if (obj->type == 'e' || obj->type == 'h' || obj->type == 'c')
		ft_rotehc(obj->obj, ft_getmat(tta, axi, cam));
}
