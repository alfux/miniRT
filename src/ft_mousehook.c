/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:40:00 by efunes            #+#    #+#             */
/*   Updated: 2023/03/05 13:45:52 by alfux            ###   ########.fr       */
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

static int	ft_dstcmp(double *dist, t_win const *win, t_list **itr)
{
	double	tdst;

	tdst = ft_distce(((t_itr *)ft_closer_to_pov(*itr,
					&win->scn.cam->pov)->content)->vtx,
			win->scn.cam->pov);
	if (tdst < *dist || *dist == 0)
	{
		*dist = tdst;
		return (ft_lstclear_return(itr, 1));
	}
	else
		return (ft_lstclear_return(itr, 0));
}

static t_obj	*ft_obj_select(t_win *win, t_vec const *ray,
				t_obj *obj)
{
	t_list	*itr;
	t_obj	*sav;
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
		if (itr && ft_dstcmp(&dist, win, &itr))
			sav = obj;
		obj = obj->next;
	}
	if (sav)
		win->hlp = win->hlp % 2 + 2;
	return (sav);
}

int	ft_mousehook(int mid, int x, int y, t_win *win)
{
	t_vec	ray;

	if (x < 0 || y < 0 || x > RESOLUTION || y > RESOLUTION * 9 / 16)
		return (0);
	if (mid == M_LEFT)
	{
		ray = ft_getdir(win, y, x);
		win->cur = ft_obj_select(win, &ray, win->scn.obj);
	}
	else if (mid == M_RIGHT)
	{
		win->cur = NULL;
		win->hlp = win->hlp % 2;
	}
	mlx_clear_window(win->cid, win->wid);
	mlx_put_image_to_window(win->cid, win->wid, win->scr.iid, 0, 0);
	ft_help(win);
	return (0);
}
