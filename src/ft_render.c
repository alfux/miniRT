/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:34:54 by alfux             #+#    #+#             */
/*   Updated: 2022/12/05 09:17:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_vec	ft_getdir(t_win win, uint32_t i, uint32_t j)
{
	float	theta;
	float	phi;
	t_vec	dir;

	theta = (j + 1) * (win.scn.cam.fov / win.w) + (M_PI - win.scn.cam.fov) / 2 ;
	phi = (i + 1) * ((win.scn.cam.fov * 9) / (win.h * 16)) +
		(M_PI - ((win.scn.cam.fov * 9) / 16)) / 2;
	dir.x = cos(phi) * win.scn.cam.ver.x;
	dir.y = cos(phi) * win.scn.cam.ver.y;
	dir.z = cos(phi) * win.scn.cam.ver.z;
	dir.x += sin(phi) * cos(theta) * win.scn.cam.hor.x;
	dir.y += sin(phi) * cos(theta) * win.scn.cam.hor.y;
	dir.z += sin(phi) * cos(theta) * win.scn.cam.hor.z;
	dir.x += sin(phi) * sin(theta) * win.scn.cam.dir.x;
	dir.y += sin(phi) * sin(theta) * win.scn.cam.dir.y;
	dir.z += sin(phi) * sin(theta) * win.scn.cam.dir.z;
	printf("dir(%i, %i) = ", j, i);
	ft_print_vect(dir);
	printf("\n");
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
