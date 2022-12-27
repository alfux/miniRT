/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:01:18 by efunes            #+#    #+#             */
/*   Updated: 2022/12/27 17:41:29 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_movcoord(int kid, t_vec *vec, t_cam *cam)
{
	if (kid == K_LEFT || kid == K_Z)
		*vec = ft_sum_uv(*vec, ft_multlv(0.2, cam->hor));
	else if (kid == K_RIGHT || kid == K_S)
		*vec = ft_sum_uv(*vec, ft_multlv(-0.2, cam->hor));
	else if (kid == K_UP || kid == K_Q)
		*vec = ft_sum_uv(*vec, ft_multlv(0.2, cam->ver));
	else if (kid == K_DOWN || kid == K_D)
		*vec = ft_sum_uv(*vec, ft_multlv(-0.2, cam->ver));
	else if (kid == K_P || kid == K_R)
		*vec = ft_sum_uv(*vec, ft_multlv(0.2, cam->dir));
	else if (kid == K_M || kid == K_T)
		*vec = ft_sum_uv(*vec, ft_multlv(-0.2, cam->dir));
	if (kid == K_Z || kid == K_S || kid == K_Q || kid == K_D
		|| kid == K_R || kid == K_T)
		*vec = ft_nrmlze(*vec);
}

void	ft_movrgb(int kid, t_rgb *rgb)
{
	if (kid == K_O)
	else if (kid == K_L)
}

void	ft_movobj(int kid, t_obj *cur)
{
	if (cur->type == 'S')
		ft_mv_sph(kid, (t_sph *)(cur->obj));
	else if (cur->type == 'P')
		ft_mv_pla(kid, (t_pla *)(cur->obj));
	else if (cur->type == 'C')
		ft_mv_cyl(kid, (t_cyl *)(cur->obj));
}
