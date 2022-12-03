/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:34:54 by alfux             #+#    #+#             */
/*   Updated: 2022/12/03 17:59:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_vec	ft_getdir(t_win win, uint32_t i, uint32_t j)
{
	t_vec	dir;
	t_3x3	mat;

	(void)i;
	(void)j;
	(void)win;
	mat.top = win.scn.cam.dir;
	(void)mat;
	dir = ft_setvec(0, 0, 0);
	return (dir);
}

void	ft_render(t_win win)
{
	uint32_t	i;
	uint32_t	j;

	ft_print_scene(win.scn);
	i = -1;
	while (++i < win.h)
	{
		j = -1;
		while (++j < win.w)
			*(uint32_t *)(win.scr.iad + i * win.scr.opl + j * (win.scr.bpp / 8))
				= ft_raytra(win, ft_setlin(win.scn.cam.pov,
						ft_getdir(win, i, j)));
	}
	mlx_put_image_to_window(win.cid, win.wid, win.scr.iid, 0, 0);
}
