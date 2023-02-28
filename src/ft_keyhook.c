/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:17:07 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 17:30:15 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_rota_x(t_cam *cam, double theta)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	cam->ver = ft_multmv(m, ft_setvec(0, cos(theta), sin(theta)));
	cam->dir = ft_multmv(m, ft_setvec(0, (-1) * sin(theta), cos(theta)));
}

static void	ft_rota_y(t_cam *cam, double theta)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	cam->hor = ft_multmv(m, ft_setvec(cos(theta), 0, sin(theta)));
	cam->dir = ft_multmv(m, ft_setvec((-1) * sin(theta), 0, cos(theta)));
}

static void	ft_rota_z(t_cam *cam, double theta)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	cam->hor = ft_multmv(m, ft_setvec(cos(theta), sin(theta), 0));
	cam->ver = ft_multmv(m, ft_setvec((-1) * sin(theta), cos(theta), 0));
}

static void	ft_movcam(int kid, t_cam *cam)
{
	if (kid == K_Q)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->hor));
	else if (kid == K_D)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->hor));
	else if (kid == K_P)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->ver));
	else if (kid == K_M)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->ver));
	else if (kid == K_Z)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->dir));
	else if (kid == K_S)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->dir));
	else if (kid == K_UP)
		ft_rota_x(cam, -6 * M_PI / 360);
	else if (kid == K_DOWN)
		ft_rota_x(cam, 6 * M_PI / 360);
	else if (kid == K_LEFT)
		ft_rota_y(cam, -6 * M_PI / 360);
	else if (kid == K_RIGHT)
		ft_rota_y(cam, 6 * M_PI / 360);
	else if (kid == K_A)
		ft_rota_z(cam, -6 * M_PI / 360);
	else if (kid == K_E)
		ft_rota_z(cam, 6 * M_PI / 360);
}

int	ft_keyhook(int kid, t_win *win)
{
	printf("Keycode: %i\n", kid);
	if (kid == K_SPACE)
		ft_print_scene(win->scn);
	if (kid == K_COMA)
	{
		if (!win->mod)
			win->mod = 1;
		else
		{
			win->mod = 0;
			ft_render(win);
		}
	}
	else if (kid == K_ESCAPE)
		return (ft_exit(win, 0));
	else if (win->mod && !win->cur && kid == K_O)
		win->scn.cam->fov += (2 * M_PI) / 360;
	else if (win->mod && !win->cur && kid == K_L)
		win->scn.cam->fov -= (2 * M_PI) / 360;
	else if (win->mod && kid == EEGGS)
		ft_eeggs(win->scn.cam);
	else if (win->mod && !win->cur)
		ft_movcam(kid, win->scn.cam);
	else if (win->mod)
		ft_movobj(kid, win->cur, win->scn.cam);
	if (win->mod)
		ft_render(win);
	return (0);
}
