/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:01:18 by efunes            #+#    #+#             */
/*   Updated: 2023/03/02 16:01:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//static void	ft_rota_obj(t_vec *vec, t_cam *cam, double theta, char id)
//{
//	t_3x3	m;
//	t_vec	tmp;
//
//	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
//	tmp = ft_multmv(ft_invmat(m), *vec);
//	if (id == 'H')
//	{
//		vec->x = tmp.x;
//		vec->y = tmp.y * cos(theta) - tmp.z * sin(theta);
//		vec->z = tmp.z * cos(theta) + tmp.y * sin(theta);
//	}
//	else if (id == 'V')
//	{
//		vec->x = tmp.x * cos(theta) + tmp.z * sin(theta);
//		vec->y = tmp.y;
//		vec->z = tmp.z * cos(theta) - tmp.x * sin(theta);
//	}
//	else if (id == 'D')
//	{
//		vec->x = tmp.x * cos(theta) - tmp.y * sin(theta);
//		vec->y = tmp.y * cos(theta) + tmp.x * sin(theta);
//		vec->z = tmp.z;
//	}
//	*vec = ft_nrmlze(ft_multmv(m, *vec));
//}

static void	ft_movcoord(int kid, t_obj const *obj, t_cam const *cam)
{
	if (kid == K_Z)
		ft_trnslt(obj, ft_multlv(0.2, cam->ver));
	else if (kid == K_S)
		ft_trnslt(obj, ft_multlv(-0.2, cam->ver));
	else if (kid == K_Q)
		ft_trnslt(obj, ft_multlv(0.2, cam->hor));
	else if (kid == K_D)
		ft_trnslt(obj, ft_multlv(-0.2, cam->hor));
	else if (kid == K_A)
		ft_trnslt(obj, ft_multlv(0.2, cam->dir));
	else if (kid == K_E)
		ft_trnslt(obj, ft_multlv(-0.2, cam->dir));
	if (kid == K_LEFT)
		ft_rotobj(obj, -M_PI / 60, 'y', cam);
	else if (kid == K_RIGHT)
		ft_rotobj(obj, M_PI / 60, 'y', cam);
	else if (kid == K_UP)
		ft_rotobj(obj, M_PI / 60, 'x', cam);
	else if (kid == K_DOWN)
		ft_rotobj(obj, -M_PI / 60, 'x', cam);
	else if (kid == K_P)
		ft_rotobj(obj, -M_PI / 60, 'z', cam);
	else if (kid == K_M)
		ft_rotobj(obj, M_PI / 60, 'z', cam);
}

static void	ft_movrgb(int kid, t_rgb *rgb)
{
	if (kid == K_F)
		rgb->r += 1;
	else if (kid == K_C)
		rgb->r -= 1;
	else if (kid == K_G)
		rgb->g += 1;
	else if (kid == K_V)
		rgb->g -= 1;
	else if (kid == K_H)
		rgb->b += 1;
	else if (kid == K_B)
		rgb->b -= 1;
	else if (kid == K_J)
		rgb->a += 1;
	else if (kid == K_N)
		rgb->a -= 1;
}

static void	ft_change_color(int kid, t_obj *cur)
{
	if (cur->type == 'S')
		ft_movrgb(kid, &((t_sph *)(cur->obj))->col);
	else if (cur->type == 'P')
		ft_movrgb(kid, &((t_pla *)(cur->obj))->col);
	else if (cur->type == 'C')
		ft_movrgb(kid, &((t_cyl *)(cur->obj))->col);
	else if (cur->type == 'L')
		ft_movrgb(kid, &((t_lig *)(cur->obj))->col);
	else if (cur->type == 'p')
		ft_movrgb(kid, &((t_pbol *)(cur->obj))->col);
	else if (cur->type == 'e' || cur->type == 'h' || cur->type == 'c')
		ft_movrgb(kid, &((t_ehc *)(cur->obj))->col);
}

void	ft_movobj(int kid, t_obj *cur, t_cam *cam)
{
	if (kid == K_Z || kid == K_S || kid == K_A || kid == K_D
		|| kid == K_Q || kid == K_E || kid == K_LEFT || kid == K_RIGHT
		|| kid == K_UP || kid == K_DOWN || kid == K_P || kid == K_M)
		ft_movcoord(kid, cur, cam);
	else if (kid == K_I || kid == K_K || kid == K_O || kid == K_L)
		ft_rscale(kid, cur);
	else
		ft_change_color(kid, cur);
}
