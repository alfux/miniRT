/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:17:07 by alfux             #+#    #+#             */
/*   Updated: 2022/12/20 18:48:44 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static void	ft_rota_x(t_cam *cam, float theta)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	cam->ver = ft_multmv(m, ft_setvec(0, cos(theta), sin(theta)));
	cam->dir = ft_multmv(m, ft_setvec(0, (-1) * sin(theta), cos(theta)));
}

static void	ft_rota_y(t_cam *cam, float theta)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	cam->hor = ft_multmv(m, ft_setvec(cos(theta), 0, sin(theta)));
	cam->dir = ft_multmv(m, ft_setvec((-1) * sin(theta), 0, cos(theta)));
}

static void	ft_rota_z(t_cam *cam, float theta)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	cam->hor = ft_multmv(m, ft_setvec(cos(theta), sin(theta), 0));
	cam->ver = ft_multmv(m, ft_setvec((-1) * sin(theta), cos(theta), 0));
}

static void	ft_movcam(int kid, t_cam *cam)
{
	if (kid == K_LEFT)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->hor));
	else if (kid == K_RIGHT)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->hor));
	else if (kid == K_UP)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->ver));
	else if (kid == K_DOWN)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->ver));
	else if (kid == K_P)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(0.2, cam->dir));
	else if (kid == K_M)
		cam->pov = ft_sum_uv(cam->pov, ft_multlv(-0.2, cam->dir));
	else if (kid == K_Z)
		ft_rota_x(cam, -0.1);
	else if (kid == K_S)
		ft_rota_x(cam, 0.1);
	else if (kid == K_Q)
		ft_rota_y(cam, -0.1);
	else if (kid == K_D)
		ft_rota_y(cam, 0.1);
	else if (kid == K_R)
		ft_rota_z(cam, -0.1);
	else if (kid == K_T)
		ft_rota_z(cam, 0.1);
}

int	ft_keyhook(int kid, t_win *win)
{
	printf("Keycode: %i\n", kid);
	if (kid == K_ESCAPE)
		return (ft_exit(win, 0));
	if (kid == K_SPACE)
		ft_print_scene(win->scn);
	ft_movcam(kid, win->scn.cam);
	ft_render(win);
	return (0);
}
