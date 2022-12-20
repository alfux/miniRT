/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:17:07 by alfux             #+#    #+#             */
/*   Updated: 2022/12/20 16:54:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static void	ft_rota_x(t_cam *cam, float theta)
{
	cam->ver = ft_setvec(0, cos(theta), sin(theta));
	cam->dir = ft_setvec(0, (-1) * sin(theta), cos(theta));
}

static void	ft_rota_y(t_cam *cam, float theta)
{
	cam->hor = ft_setvec(cos(theta), 0, sin(theta));
	cam->dir = ft_setvec((-1) * sin(theta), 0, cos(theta));
}

static void	ft_rota_z(t_cam *cam, float theta)
{
	cam->hor = ft_setvec(cos(theta), sin(theta), 0);
	cam->ver = ft_setvec((-1) * sin(theta), cos(theta), 0);
}

static void	ft_movcam(int kid, t_win *win)
{
	if (kid == K_LEFT)
		win->scn.cam->pov.x += 0.2;
	else if (kid == K_RIGHT)
		win->scn.cam->pov.x -= 0.2;
	else if (kid == K_UP)
		win->scn.cam->pov.y += 0.2;
	else if (kid == K_DOWN)
		win->scn.cam->pov.y -= 0.2;
	else if (kid == K_P)
		win->scn.cam->pov.z += 0.2;
	else if (kid == K_M)
		win->scn.cam->pov.z -= 0.2;
	else if (kid == K_Z)
		ft_rota_x(win->scn.cam, -0.1);
	else if (kid == K_S)
		ft_rota_x(win->scn.cam, 0.1);
	else if (kid == K_Q)
		ft_rota_y(win->scn.cam, -0.1);
	else if (kid == K_D)
		ft_rota_y(win->scn.cam, 0.1);
	else if (kid == K_R)
		ft_rota_z(win->scn.cam, -0.1);
	else if (kid == K_T)
		ft_rota_z(win->scn.cam, 0.1);
	*win = ft_tobase_cam(*win);
}

int	ft_keyhook(int kid, t_win *win)
{
	printf("Keycode: %i\n", kid);
	if (kid == K_ESCAPE)
		return (ft_exit(win, 0));
	ft_movcam(kid, win);
	ft_render(win);
	return (0);
}
