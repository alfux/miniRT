/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shades.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:22:41 by alfux             #+#    #+#             */
/*   Updated: 2022/12/27 11:58:12 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static int	ft_is_obstacle(t_2x3 const *i, t_vec const *vec, t_vec const *ldir,
				float norm)
{
	if (ft_is_sol(i))
		if (((ft_scalar(ft_dif_uv(i->top, *vec), *ldir) > 0
					&& ft_distce(i->top, *vec) < norm)
				|| (ft_scalar(ft_dif_uv(i->bot, *vec), *ldir) > 0
					&& ft_distce(i->bot, *vec) < norm)))
			return (1);
	return (0);
}

static int	ft_shadow(t_win const *win, t_vec const *vec, t_vec const *lpos,
	t_obj const *obj)
{
	t_obj	*lst;
	t_vec	ldir;
	float	norm;
	t_2x3	obs;

	lst = win->scn.obj;
	ldir = ft_nrmlze(ft_dif_uv(*lpos, *vec));
	norm = ft_distce(*lpos, *vec);
	while (lst)
	{
		obs = ft_sysres(&ldir, vec, lst);
		if (lst == obj && ft_deadzn(&obs, vec, EPSILON))
		{
			lst = lst->next;
			continue ;
		}
		if (ft_deadzn(&obs, lpos, DEADZONE)
			|| ft_is_obstacle(&obs, vec, &ldir, norm))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_rgb	ft_shades(t_win const *win, t_obj const *obj, t_vec const *vec,
	t_rgb const *rgb)
{
	float	i;

	if (!obj)
		return (*rgb);
	if (obj->type == 'S')
		i = ft_shdsph(win, (t_sph *)obj->obj, vec);
	else if (obj->type == 'P')
		i = ft_shdpla(win, (t_pla *)obj->obj, vec);
	else if (obj->type == 'C')
		i = ft_shdcyl(win, (t_cyl *)obj->obj, vec);
	else
		i = 0;
	if (i < 0.f || ft_shadow(win, vec, &((t_lig *)win->scn.lig->obj)->pos, obj))
		i = 0;
	i = ((t_lig *)win->scn.lig->obj)->rat * i + win->scn.amb.rat * (1 - i);
	return (ft_setrgb(rgb->r * i, rgb->g * i, rgb->b * i));
}
