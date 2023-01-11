/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:40:00 by efunes            #+#    #+#             */
/*   Updated: 2023/01/11 12:26:34 by alfux            ###   ########.fr       */
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

static t_obj	*ft_obj_select(t_win const *win, t_vec const *ray,
				t_obj *obj)
{
	t_list	*itr;
	t_obj	*sav;
	double	tdst;
	double	dist;

	sav = (t_obj *)0;
	dist = 0;
	while (obj)
	{
		itr = ft_sysres(ray, &win->scn.cam->pov, obj);
		if (itr == (void *)-1)
			ft_exit_failure((t_win *)win, "malloc error: ");
		if (itr)
			ft_keep_face_cam(&itr, &win->scn.cam->pov, ray);
		if (itr)
		{
			tdst = ft_distce(((t_itr *)ft_closer_to_pov(itr,
							&win->scn.cam->pov)->content)->vtx,
					win->scn.cam->pov);
			if (tdst < dist || dist == 0)
				sav = obj + ft_lstclear_return(&itr, 0);
		}
		obj = obj->next;
	}
	return (sav);
}

int	ft_mousehook(int mid, int x, int y, t_win *win)
{
	t_vec	ray;

	printf("Mouse - Keycode: %i\n", mid);
	if (mid == M_LEFT)
	{
		ray = ft_getdir(win, x, y);
		win->cur = ft_obj_select(win, &ray, win->scn.obj);
	}
	else if (mid == M_RIGHT)
		win->cur = NULL;
	return (0);
}
