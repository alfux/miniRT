/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:17:07 by alfux             #+#    #+#             */
/*   Updated: 2023/03/08 16:27:20 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_rota(t_cam *cam, double theta, char xyz)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	if (xyz == 'x')
	{
		cam->ver = ft_multmv(m, ft_setvec(0, cos(theta), sin(theta)));
		cam->dir = ft_multmv(m, ft_setvec(0, (-1) * sin(theta), cos(theta)));
	}
	if (xyz == 'y')
	{
		cam->hor = ft_multmv(m, ft_setvec(cos(theta), 0, sin(theta)));
		cam->dir = ft_multmv(m, ft_setvec((-1) * sin(theta), 0, cos(theta)));
	}
	if (xyz == 'z')
	{
		cam->hor = ft_multmv(m, ft_setvec(cos(theta), sin(theta), 0));
		cam->ver = ft_multmv(m, ft_setvec((-1) * sin(theta), cos(theta), 0));
	}
}

static void	ft_modamb(int kid, t_amb *amb)
{
	if (kid == K_I)
		amb->rat = fmin(1, amb->rat + 0.01);
	else if (kid == K_K)
		amb->rat = fmax(0, amb->rat - 0.01);
	else if (kid == K_F)
		amb->col.r += 1;
	else if (kid == K_C)
		amb->col.r -= 1;
	else if (kid == K_G)
		amb->col.g += 1;
	else if (kid == K_V)
		amb->col.g -= 1;
	else if (kid == K_H)
		amb->col.b += 1;
	else if (kid == K_B)
		amb->col.b -= 1;
}

static void	ft_movcam(int kid, t_cam *cam, t_amb *amb)
{
	if (kid == K_Q)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->hor));
	else if (kid == K_D)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->hor));
	else if (kid == K_A)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->ver));
	else if (kid == K_E)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->ver));
	else if (kid == K_Z)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->dir));
	else if (kid == K_S)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->dir));
	else if (kid == K_UP)
		ft_rota(cam, -6 * M_PI / 360, 'x');
	else if (kid == K_DOWN)
		ft_rota(cam, 6 * M_PI / 360, 'x');
	else if (kid == K_LEFT)
		ft_rota(cam, -6 * M_PI / 360, 'y');
	else if (kid == K_RIGHT)
		ft_rota(cam, 6 * M_PI / 360, 'y');
	else if (kid == K_P)
		ft_rota(cam, -6 * M_PI / 360, 'z');
	else if (kid == K_M)
		ft_rota(cam, 6 * M_PI / 360, 'z');
	ft_modamb(kid, amb);
}

static int	ft_keyh2(int kid, t_win *win)
{
	if (kid == K_ESCAPE)
		return (ft_exit(win, 0));
	else if (win->mod && kid == K_TI)
		win->scn.cam = win->scn.cam->prev;
	else if (win->mod && kid == K_ONE)
		win->scn.cam = win->scn.cam->next;
	else if (win->mod && !win->cur && (kid == K_O || kid == K_L))
		win->scn.cam->fov += ((kid == K_O) - (kid == K_L)) * (2 * M_PI) / 360;
	else if (win->mod && kid == EEGGS)
		ft_eeggs(win->scn.cam);
	else if (win->mod && !win->cur)
		ft_movcam(kid, win->scn.cam, &win->scn.amb);
	else if (win->mod)
		ft_movobj(kid, win->cur, win->scn.cam);
	if (win->mod)
		ft_render(win);
	else
	{
		mlx_clear_window(win->cid, win->wid);
		mlx_put_image_to_window(win->cid, win->wid, win->scr.iid, 0, 0);
		ft_help(win);
	}
	return (0);
}

int	ft_keyhook(int kid, t_win *win)
{
	if (kid == K_TAB)
	{
		win->hlp = win->hlp % 2 + 4;
		win->cur = ft_sellig(win->cur, win->scn.lig);
	}
	else if (kid == K_PT)
	{
		if (win->hlp % 2)
			win->hlp--;
		else
			win->hlp++;
	}
	else if (kid == K_COMA)
	{
		if (!win->mod)
			win->mod = 1;
		else
		{
			win->mod = 0;
			ft_render(win);
		}
	}
	ft_keyh2(kid, win);
	return (0);
}
