/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setwin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:23:07 by alfux             #+#    #+#             */
/*   Updated: 2022/12/03 18:09:09 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_win	ft_setwin(int width, int height, char *title)
{
	t_win	win;

	ft_bzero(&win, sizeof (t_win));
	win.cid = mlx_init();
	win.wid = mlx_new_window(win.cid, width, height, title);
	win.scr.iid = mlx_new_image(win.cid, width, height);
	win.scr.iad = mlx_get_data_addr(win.scr.iid, &win.scr.bpp, &win.scr.opl,
			&win.scr.end);
	win.w = width;
	win.h = height;
	return (win);
}
