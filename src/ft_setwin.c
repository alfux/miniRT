/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setwin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:23:07 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 18:59:54 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_win	ft_setwin(int width, int height, char *title)
{
	t_win	win;

	win.cid = mlx_init();
	win.wid = mlx_new_window(win.cid, width, height, title);
	win.scr.iid = mlx_new_image(win.cid, width, height);
	win.scr.iad = mlx_get_data_addr(win.scr.iid, &win.scr.bpp, &win.scr.opl,
			&win.scr.end);
	win.w = width;
	win.h = height;
	win.scn.cam = ft_setcam(ft_setvec(0, 0, 0), ft_setvec(0, 0, 0), 0);
	win.scn.amb = ft_setamb(0.f, ft_setrgb(0, 0, 0));
	win.scn.lig = (t_obj *)0;
	win.scn.obj = (t_obj *)0;
	return (win);
}
