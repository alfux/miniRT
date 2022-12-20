/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:32:12 by alfux             #+#    #+#             */
/*   Updated: 2022/12/20 16:58:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static void	ft_objlst_tobase(t_3x3 *m, t_obj *lst)
{
	while (lst)
	{
		if (lst->type == 'L')
			((t_lig *)lst->obj)->pos = ft_multmv(*m, ((t_lig *)lst->obj)->pos);
		else if (lst->type == 'S')
			((t_sph *)lst->obj)->pos = ft_multmv(*m, ((t_sph *)lst->obj)->pos);
		else if (lst->type == 'P')
		{
			((t_pla *)lst->obj)->pos = ft_multmv(*m, ((t_pla *)lst->obj)->pos);
			((t_pla *)lst->obj)->dir = ft_multmv(*m, ((t_pla *)lst->obj)->dir);
		}
		else if (lst->type == 'C')
		{
			((t_cyl *)lst->obj)->pos = ft_multmv(*m, ((t_cyl *)lst->obj)->pos);
			((t_cyl *)lst->obj)->dir = ft_multmv(*m, ((t_cyl *)lst->obj)->dir);
		}
		lst = lst->next;
	}
}

t_win	ft_tobase_cam(t_win win)
{
	t_3x3	m;

	m = ft_invmat(ft_set3x3(win.scn.cam->hor, win.scn.cam->ver,
				win.scn.cam->dir));
	win.scn.cam->pov = ft_multmv(m, win.scn.cam->pov);
	win.scn.cam->dir = ft_multmv(m, win.scn.cam->dir);
	win.scn.cam->ver = ft_multmv(m, win.scn.cam->ver);
	win.scn.cam->hor = ft_multmv(m, win.scn.cam->hor);
	ft_objlst_tobase(&m, win.scn.lig);
	ft_objlst_tobase(&m, win.scn.obj);
	return (win);
}
