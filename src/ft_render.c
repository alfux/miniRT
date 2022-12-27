/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:34:54 by alfux             #+#    #+#             */
/*   Updated: 2022/12/27 11:50:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_vec	ft_getdir(t_win const *win, uint32_t i, uint32_t j)
{
	float	theta;
	float	phi;
	t_vec	dir;

	theta = (j + 1) * (win->scn.cam->fov / win->w) + (M_PI - win->scn.cam->fov)
		/ 2 ;
	phi = (i + 1) * ((win->scn.cam->fov * 9) / (win->h * 16))
		+ (M_PI - ((win->scn.cam->fov * 9) / 16)) / 2;
	dir = ft_sum_uv(ft_sum_uv(ft_multlv(cos(phi), win->scn.cam->ver),
				ft_multlv(sin(phi) * cos(theta), win->scn.cam->hor)),
			ft_multlv(sin(phi) * sin(theta), win->scn.cam->dir));
	return (dir);
}

void	ft_big_pixel(t_win const *win, uint32_t i, uint32_t j, uint32_t rgb)
{
	uint32_t	lin;
	uint32_t	col;
	char		*pix;

	pix = win->scr.iad + 4 * i * win->scr.opl + 4 * j * (win->scr.bpp / 8);
	lin = -1;
	while (++lin < 4 && i + lin < win->h)
	{
		col = -1;
		while (++col < 4 && j + col < win->w)
			*(uint32_t *)(pix + (i + lin) * win->scr.opl + (j + col) * (win->scr.bpp / 8))
				= rgb;
	}
}

void	ft_low_render(t_win const *win)
{
	uint32_t	i;
	uint32_t	j;
	t_vec		ray;

	i = -1;
	while (++i < 180)
	{
		j = -1;
		while (++j < 320)
		{
			ray = ft_getdir(win, i, j);
			ft_big_pixel(win, i, j, ft_raytra(win, &ray, win->scn.obj));
		}
	}
}

void	ft_render(t_win const *win, int flag)
{
	uint32_t	i;
	uint32_t	j;
	t_vec		ray;

	if (flag == LOWRES)
		return (ft_low_render(win));
	i = -1;
	while (++i < win->h)
	{
		j = -1;
		while (++j < win->w)
		{
			ray = ft_getdir(win, i, j);
			*(uint32_t *)(win->scr.iad + i * win->scr.opl + j
					* (win->scr.bpp / 8)) = ft_raytra(win, &ray, win->scn.obj);
		}
	}
	mlx_clear_window(win->cid, win->wid);
	mlx_put_image_to_window(win->cid, win->wid, win->scr.iid, 0, 0);
}
