/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:40:00 by efunes            #+#    #+#             */
/*   Updated: 2023/01/11 15:26:34 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_obj	*ft_obj_select(t_win const *win, t_vec const *ray,
				t_obj *obj)
{
	t_2x3	intr;
	t_vec	tmp;
	t_vec	vec;
	t_obj	*sav;

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
				sav = obj;
			}
		}
		obj = obj->next;
	}
	return (sav);
}

int	ft_mousehook(int mid, int x, int y, t_win *win)
{
	t_vec	ray;

	printf("Mouse - Keycode: %i - x %d, y %d\n", mid, x, y);
	if (x < 0 || y < 0 || x > RESOLUTION || y > RESOLUTION * 9 / 16)
		return (0);
	if (mid == M_LEFT)
	{
		ray = ft_getdir(win, y, x);
		printf("Mouse - ray.x %f, ray.y %f, ray.z %f\n", ray.x, ray.y, ray.z);
		win->cur = ft_obj_select(win, &ray, win->scn.obj);
	}
	else if (mid == M_RIGHT)
		win->cur = NULL;
	return (0);
}
