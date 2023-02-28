/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ehcrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:12:19 by alfux             #+#    #+#             */
/*   Updated: 2023/02/27 20:14:52 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_zone(double rad, t_ehc const *ehc)
{
	rad = rad - floor(rad / ehc->bns.dam.size) * ehc->bns.dam.size;
	if (rad < ehc->bns.dam.size / 2)
		return (1);
	return (-1);
}

static t_rgb	ft_hyprgb(t_vec const *vtx, t_vec const *nml, t_ehc const *ehc)
{
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(ehc->bns.dam.bas) == 0.f)
		return (ehc->col);
	vec = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.dam.bas), *nml));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	phi = ft_scalar(ft_setvec(ehc->bns.dam.bas.top.z, ehc->bns.dam.bas.mid.z, ehc->bns.dam.bas.bot.z), ft_dif_uv(*vtx, ft_multmv(ehc->bas, ehc->pos)));
	if (ft_zone(phi, ehc) * ft_zone(theta, ehc) == 1)
		return (ehc->col);
	return (ehc->bns.dam.col);
}

static t_rgb	ft_ellrgb(t_vec const *nml, t_ehc const *ehc)
{
	t_vec	vec;
	double	theta;
	double	phi;

	if (ft_det3x3(ehc->bns.dam.bas) == 0.f)
		return (ehc->col);
	vec = ft_nrmlze(ft_multmv(ft_invmat(ehc->bns.dam.bas), *nml));
	phi = acos(vec.z);
	theta = asin(vec.y / sin(phi));
	if (theta >= 0)
		theta = acos(vec.x / sin(phi));
	else
		theta = -acos(vec.x / sin(phi));
	if (ft_zone(phi, ehc) * ft_zone(theta, ehc) == 1)
		return (ehc->col);
	return (ehc->bns.dam.col);
}

t_rgb	ft_ehcrgb(t_vec const *vtx, t_vec const *nml, t_ehc const *ehc)
{
	if (ehc->typ == 'e')
		return (ft_ellrgb(nml, ehc));
	else if (ehc->typ == 'h' || ehc->typ == 'c')
		return (ft_hyprgb(vtx, nml, ehc));
	return (ehc->col);
}
