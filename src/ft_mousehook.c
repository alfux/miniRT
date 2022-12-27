/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:40:00 by efunes            #+#    #+#             */
/*   Updated: 2022/12/27 16:37:33 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_movobj(int kitm, t_win *win)
{
	
}

static t_obj	*ft_obj_select(t_win const *win, t_vec const *ray,
				t_obj *obj)
{
	t_2x3	intr;
	t_vec	tmp;
	t_vec	vec;
	t_rgb	rgb;
	t_obj	*sav;

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
	return (sav);
}

int	ft_mousehook(int kid, int x, int y, t_win *win)
{
	t_vec	ray;

	printf("Mouse - Keycode: %i\n", kid);
	if (kid == M_LEFT)
	{
		ray = ft_getdir(win, x, y);
		win->cur = ft_obj_select(win, &ray, win->scn.obj);
	}
	else if (kid == M_RIGHT)
		win->cur = NULL;
	return (0);
}
