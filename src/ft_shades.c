/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shades.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:22:41 by alfux             #+#    #+#             */
/*   Updated: 2022/12/21 12:30:00 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static int	ft_shadow(t_win const *win, t_obj const *obj, t_vec const *vec,
				t_vec const *dir)
{
	t_obj	*lst;
	t_vec	ndir;
	float	norm;
	t_2x3	obs;

	lst = win->scn.obj;
	ndir = ft_nrmlze(*dir);
	norm = ft_norm(*dir);
	obs = ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN));
	while (lst)
	{
		if (lst != obj)
		{
			obs = ft_sysres(&ndir, vec, lst);
			if (!isnan(obs.top.x) && !isnan(obs.bot.x)
				&& ((ft_scalar(ft_dif_uv(obs.top, *vec), ndir) > 0
						&& ft_distce(obs.top, *vec) < norm)
					|| (ft_scalar(ft_dif_uv(obs.bot, *vec), ndir) > 0
						&& ft_distce(obs.bot, *vec) < norm)))
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

t_rgb	ft_shades(t_win const *win, t_obj const *obj, t_vec const *vec,
	t_rgb const *rgb)
{
	t_vec	dir;
	float	i;

	if (!obj)
		return (*rgb);
	dir = ft_dif_uv(((t_lig *)win->scn.lig->obj)->pos, *vec);
	if (obj->type == 'S')
		i = ft_scalar(ft_nrmlze(dir), ft_nrmlze(ft_dif_uv(*vec,
						((t_sph *)obj->obj)->pos)));
	else if (obj->type == 'P')
		i = fabs(ft_scalar(ft_nrmlze(dir),
					ft_nrmlze(((t_pla *)obj->obj)->dir)));
	else if (obj->type == 'C')
		i = 1;
	else
		i = 0;
	if (i < 0.f || ft_shadow(win, obj, vec, &dir))
		i = 0;
	i = ((t_lig *)win->scn.lig->obj)->rat * i + win->scn.amb.rat * (1 - i);
	return (ft_setrgb(rgb->r * i, rgb->g * i, rgb->b * i));
}
