/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:01:18 by efunes            #+#    #+#             */
/*   Updated: 2023/01/11 15:52:51 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_rota_obj(t_vec *vec, t_cam *cam, double theta, char id)
{
	t_3x3	m;

	m = ft_set3x3(cam->hor, cam->ver, cam->dir);
	*vec = ft_multmv(ft_invmat(m), *vec);
	if (id == 'H')
	{
		vec->y = vec->y * cos(theta) - vec->z * sin(theta);
		vec->z = vec->z * cos(theta) + vec->y * sin(theta);
	}
	else if (id == 'V')
	{
		vec->x = vec->x * cos(theta) + vec->z * sin(theta);
		vec->z = vec->z * cos(theta) - vec->x * sin(theta);
	}
	else if (id == 'D')
	{
		vec->x = vec->x * cos(theta - vec->y * sin(theta));
		vec->y = vec->y * cos(theta) + vec->x * sin(theta);
	}
	*vec = ft_multmv(m, *vec);
}

static void	ft_movcoord(int kid, t_vec *vec, t_cam *cam)
{
	if (kid == K_Z)
		*vec = ft_sum_uv(*vec, ft_multlv(0.2, cam->hor));
	else if (kid == K_S)
		*vec = ft_sum_uv(*vec, ft_multlv(-0.2, cam->hor));
	else if (kid == K_Q)
		*vec = ft_sum_uv(*vec, ft_multlv(0.2, cam->ver));
	else if (kid == K_D)
		*vec = ft_sum_uv(*vec, ft_multlv(-0.2, cam->ver));
	else if (kid == K_A)
		*vec = ft_sum_uv(*vec, ft_multlv(0.2, cam->dir));
	else if (kid == K_E)
		*vec = ft_sum_uv(*vec, ft_multlv(-0.2, cam->dir));
	else if (kid == K_LEFT)
		ft_rota_obj(vec, cam, M_PI / 60, 'H');
	else if (kid == K_RIGHT)
		ft_rota_obj(vec, cam, -1 * M_PI / 60, 'H');
	else if (kid == K_UP)
		ft_rota_obj(vec, cam, M_PI / 60, 'V');
	else if (kid == K_DOWN)
		ft_rota_obj(vec, cam, -1 * M_PI / 60, 'V');
	else if (kid == K_P)
		ft_rota_obj(vec, cam, M_PI / 60, 'D');
	else if (kid == K_M)
		ft_rota_obj(vec, cam, -1 * M_PI / 60, 'D');
}

static void	ft_movrgb(int kid, t_rgb *rgb)
{
	if (kid == K_F)
		rgb->r -= 1;
	else if (kid == K_C)
		rgb->r += 1;
	else if (kid == K_G)
		rgb->g -= 1;
	else if (kid == K_V)
		rgb->g += 1;
	else if (kid == K_H)
		rgb->b -= 1;
	else if (kid == K_B)
		rgb->b += 1;
	else if (kid == K_J)
		rgb->a -= 1;
	else if (kid == K_N)
		rgb->a += 1;
}

static void	ft_change_color(int kid, t_obj *cur)
{
	if (kid == K_K && cur->type == 'S')
		((t_sph *)(cur->obj))->dia /= 1.2;
	else if (kid == K_K && cur->type == 'C')
		((t_cyl *)(cur->obj))->dia /= 1.2;
	else if (kid == K_O && cur->type == 'C')
		((t_cyl *)(cur->obj))->hgt *= 1.2;
	else if (kid == K_L && cur->type == 'C')
		((t_cyl *)(cur->obj))->hgt /= 1.2;
	else if (kid == K_F || kid == K_G || kid == K_H || kid == K_J
		|| kid == K_C || kid == K_V || kid == K_B || kid == K_N)
	{
		if (cur->type == 'S')
			ft_movrgb(kid, &((t_sph *)(cur->obj))->col);
		else if (cur->type == 'P')
			ft_movrgb(kid, &((t_pla *)(cur->obj))->col);
		else if (cur->type == 'C')
			ft_movrgb(kid, &((t_cyl *)(cur->obj))->col);
	}
}

void	ft_movobj(int kid, t_obj *cur, t_cam *cam)
{
	if (kid == K_Z || kid == K_S || kid == K_A || kid == K_D
		|| kid == K_Q || kid == K_E)
	{
		if (cur->type == 'S')
			ft_movcoord(kid, &((t_sph *)(cur->obj))->pos, cam);
		else if (cur->type == 'P')
			ft_movcoord(kid, &((t_pla *)(cur->obj))->pos, cam);
		else if (cur->type == 'C')
			ft_movcoord(kid, &((t_cyl *)(cur->obj))->pos, cam);
	}
	else if (kid == K_LEFT || kid == K_RIGHT
		|| kid == K_UP || kid == K_DOWN || kid == K_P || kid == K_M)
	{
		if (cur->type == 'P')
			ft_movcoord(kid, &((t_pla *)(cur->obj))->dir, cam);
		else if (cur->type == 'C')
			ft_movcoord(kid, &((t_cyl *)(cur->obj))->dir, cam);
	}
	else if (kid == K_I && cur->type == 'S')
		((t_sph *)(cur->obj))->dia *= 1.2;
	else if (kid == K_I && cur->type == 'C')
		((t_cyl *)(cur->obj))->dia *= 1.2;
	else
		ft_change_color(kid, cur);
}
