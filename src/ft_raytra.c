/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:13:11 by alfux             #+#    #+#             */
/*   Updated: 2022/12/21 21:04:43 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_vec	ft_closer_to_pov(t_2x3 const *cmp, t_vec const *pov)
{
	if (isnan(cmp->top.x) || isnan(cmp->top.y) || isnan(cmp->top.z))
		return (cmp->bot);
	if (isnan(cmp->bot.x) || isnan(cmp->bot.y) || isnan(cmp->bot.z))
		return (cmp->top);
	if (ft_distce(cmp->top, *pov) < ft_distce(cmp->bot, *pov))
		return (cmp->top);
	return (cmp->bot);
}

static int	ft_iscloser(t_vec const *vec, t_vec const *tmp, t_vec const *pov)
{
	if (isnan(tmp->x) || isnan(tmp->y) || isnan(tmp->z))
		return (0);
	if ((isnan(vec->x) && isnan(vec->y) && isnan(vec->z))
		|| ft_distce(*tmp, *pov) < ft_distce(*vec, *pov))
		return (1);
	return (0);
}

static t_rgb	ft_objrgb(t_obj const *obj)
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

static int	ft_face_cam(t_2x3 *inter, t_vec const *pov, t_vec const *ray)
{
	float	tscl;
	float	bscl;

	tscl = ft_scalar(*ray, ft_nrmlze(ft_dif_uv(inter->top, *pov)));
	bscl = ft_scalar(*ray, ft_nrmlze(ft_dif_uv(inter->bot, *pov)));
	if (tscl < 0.f && bscl < 0.f)
		return (0);
	return (1);
}

uint32_t	ft_raytra(t_win const *win, t_vec const *ray, t_obj const *obj)
{
	t_2x3		intr;
	t_vec		tmp;
	t_vec		vec;
	t_rgb		rgb;
	t_obj const	*sav;

	rgb = ft_setrgb(0, 0, 0);
	vec = ft_setvec(NAN, NAN, NAN);
	sav = (t_obj *)0;
	while (obj)
	{
		intr = ft_sysres(ray, &win->scn.cam->pov, obj);
		if (ft_is_sol(&intr) && ft_face_cam(&intr, &win->scn.cam->pov, ray))
		{
			tmp = ft_closer_to_pov(&intr, &win->scn.cam->pov);
			if (ft_iscloser(&vec, &tmp, &win->scn.cam->pov))
			{
				vec = tmp;
				rgb = ft_objrgb(obj);
				sav = obj;
			}
		}
		obj = obj->next;
	}
	return (ft_rgbtoi(ft_shades(win, sav, &vec, &rgb)));
}
