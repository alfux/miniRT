/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:13:11 by alfux             #+#    #+#             */
/*   Updated: 2022/12/08 16:39:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_vec	ft_closer_to_pov(t_2x3 comp, t_vec pov)
{
	if (ft_distce(comp.top, pov) < ft_distce(comp.bot, pov))
		return (comp.top);
	return (comp.bot);
}

static int	ft_iscloser(t_vec vec, t_vec tmp, t_vec pov)
{
	if ((isnan(vec.x) && isnan(vec.y) && isnan(vec.z))
		|| ft_distce(tmp, pov) < ft_distce(vec, pov))
		return (1);
	return (0);
}

static t_rgb	ft_objrgb(t_obj *obj)
{
	if (obj->type == 'S')
	{
		return (ft_setrgb(((t_sph *)obj->obj)->col.r,
				((t_sph *)obj->obj)->col.g, ((t_sph *)obj->obj)->col.b));
	}
	else if (obj->type == 'P')
	{
		return (ft_setrgb(((t_pla *)obj->obj)->col.r,
				((t_pla *)obj->obj)->col.g, ((t_pla *)obj->obj)->col.b));
	}
	else if (obj->type == 'C')
	{
		return (ft_setrgb(((t_cyl *)obj->obj)->col.r,
				((t_cyl *)obj->obj)->col.g, ((t_cyl *)obj->obj)->col.b));
	}
	else
		return (ft_setrgb(0, 0, 0));
}

uint32_t	ft_raytra(t_win win, t_vec ray, t_obj *obj)
{
	t_2x3	inter;
	t_vec	tmp;
	t_vec	vec;
	t_rgb	rgb;
	t_obj	*sav;

	rgb = ft_setrgb(0, 0, 0);
	vec = ft_setvec(NAN, NAN, NAN);
	sav = (t_obj *)0;
	while (obj)
	{
		inter = ft_sysres(ray, win.scn.cam.pov, obj);
		if (!isnan(inter.top.x) && !isnan(inter.bot.x))
		{
			tmp = ft_closer_to_pov(inter, win.scn.cam.pov);
			if (ft_iscloser(vec, tmp, win.scn.cam.pov))
			{
				vec = tmp;
				rgb = ft_objrgb(obj);
				sav = obj;
			}
		}
		obj = obj->next;
	}
	return (ft_rgbtoi(ft_shades(win, sav, vec, rgb)));
}
