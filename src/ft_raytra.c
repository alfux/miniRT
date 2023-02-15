/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:46:15 by alfux             #+#    #+#             */
/*   Updated: 2023/02/15 18:09:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_list	*ft_closer_to_pov(t_list *itr, t_vec const *pov)
{
	t_list	*temp;
	t_list	*clsr;
	double	dist;
	double	smlst;

	temp = itr->next;
	clsr = itr;
	smlst = ft_distce(((t_itr *)clsr->content)->vtx, *pov);
	while (temp)
	{
		dist = ft_distce(((t_itr *)temp->content)->vtx, *pov);
		if (dist < smlst)
		{
			clsr = temp;
			smlst = dist;
		}
		temp = temp->next;
	}
	return (clsr);
}

static void	ft_keep_face_cam(t_list **itr, t_vec const *pov, t_vec const *ray)
{
	t_list	*buf;
	t_itr	*vtx;

	while (*itr)
	{
		vtx = (*itr)->content;
		if (ft_deadzn(&vtx->vtx, pov, DEADZONE)
			|| ft_scalar(*ray, ft_nrmlze(ft_dif_uv(vtx->vtx, *pov))) < 0)
		{
			buf = *itr;
			*itr = (*itr)->next;
			ft_lstdelone(buf, &free);
		}
		else
			itr = &(*itr)->next;
	}
}

uint32_t	ft_raytra(t_win const *win, t_vec const *ray, t_obj const *obj)
{
	t_list	*itr;
	t_list	*tmp;
	t_rgb	rgb;

	itr = (void *)0;
	tmp = (void *)0;
	while (obj)
	{
		tmp = ft_sysres(ray, &win->scn.cam->pov, obj);
		if (tmp == (void *)-1)
		{
			ft_lstclear(&itr, &free);
			ft_exit_failure((t_win *)win, "malloc error: ");
		}
		ft_lstadd_back(&itr, tmp);
		obj = obj->next;
	}
	ft_keep_face_cam(&itr, &win->scn.cam->pov, ray);
	if (!itr)
		return (0);
	rgb = ft_shades(win, ray, ft_closer_to_pov(itr, &win->scn.cam->pov));
	ft_lstclear(&itr, &free);
	return (ft_rgbtoi(rgb));
}
