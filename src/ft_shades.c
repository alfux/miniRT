/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shades.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:21:09 by alfux             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/23 16:00:51 by efunes           ###   ########.fr       */
=======
/*   Updated: 2023/03/01 13:55:42 by alfux            ###   ########.fr       */
>>>>>>> alfux
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_is_obs(t_list const *obs, t_vec const *vtx, t_vec const *ldir,
				double norm)
{
	t_itr	*itr;

	while (obs)
	{
		itr = (t_itr *)obs->content;
		if (ft_scalar(*ldir, ft_dif_uv(itr->vtx, *vtx)) > 0
			&& ft_distce(itr->vtx, *vtx) < norm)
			return (1);
		obs = obs->next;
	}
	return (0);
}

static void	ft_remdzn(t_list **obs, t_vec const *ctr, double rad)
{
	t_list	*buf;
	t_itr	*vtx;

	while (*obs)
	{
		vtx = (*obs)->content;
		if (ft_deadzn(&vtx->vtx, ctr, rad))
		{
			buf = *obs;
			*obs = (*obs)->next;
			ft_lstdelone(buf, &free);
		}
		else
			obs = &(*obs)->next;
	}
}

static int	ft_shadow(t_win const *win, t_vec const *vtx, t_vec const *lpos)
{
	t_obj	*obj;
	t_vec	ldir;
	double	norm;
	t_list	*obs;

	obj = win->scn.obj;
	ldir = ft_dif_uv(*lpos, *vtx);
	norm = ft_norm(ldir);
	ldir = ft_nrmlze(ldir);
	while (obj)
	{
		obs = ft_sysres(&ldir, vtx, obj);
		ft_remdzn(&obs, vtx, EPSILON);
		ft_remdzn(&obs, lpos, DEADZONE);
		if (!obs)
			;
		else if (ft_is_obs(obs, vtx, &ldir, norm))
			return (ft_lstclear_return(&obs, 1));
		ft_lstclear(&obs, &free);
		obj = obj->next;
	}
	return (0);
}

t_rgb	ft_shades(t_win const *win, t_vec const *ray, t_list *itr)
{
	double	i;
	t_obj	*lst;
	t_itr	*vtx;
	t_lig	*lig;
	t_rgb	rgb;

	vtx = itr->content;
	lst = win->scn.lig;
	rgb = ft_setrgb(0, 0, 0);
	while (lst)
	{
		lig = lst->obj;
		i = ft_scalar(vtx->nml, ft_nrmlze(ft_dif_uv(lig->pos, vtx->vtx)));
		if (ft_scalar(vtx->nml, ft_dif_uv(win->scn.cam->pov, vtx->vtx)) * i < 0)
			i = 0;
		else
			i = fabs(ft_scalar(vtx->bmp,
						ft_nrmlze(ft_dif_uv(lig->pos, vtx->vtx))));
		if (ft_shadow(win, &vtx->vtx, &lig->pos))
			i = 0;
		rgb = ft_addrgb(rgb, ft_ligrgb(vtx, ray, lig, pow(i, GAMMA)));
		lst = lst->next;
	}
	rgb = ft_addrgb(rgb, ft_ambrgb(&vtx->col, &win->scn.amb));
	return (rgb);
}
