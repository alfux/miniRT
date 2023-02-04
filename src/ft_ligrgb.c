/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ligrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:21 by alfux             #+#    #+#             */
/*   Updated: 2023/02/02 17:23:50 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rgb	ft_ligrgb(t_itr const *vtx, t_vec const *ray, t_lig const *lig,
	double i)
{
	t_rgb	res;
	t_vec	dir;
	double	j;

	j = 0;
	if (i > 0 && vtx->spc.siz != 0)
	{
		dir = ft_dif_uv(lig->pos, vtx->vtx);
		dir = ft_dif_uv(ft_multlv(2 * ft_scalar(dir, vtx->nml), vtx->nml), dir);
		j = fmin(1, vtx->spc.har * i * lig->rat
				* pow(fmax(0, -ft_scalar(ft_nrmlze(dir), *ray)),
				1 / vtx->spc.siz));
	}
	res.r = lig->col.r * fmin(1, j + lig->rat * i * vtx->col.r / 255);
	res.g = lig->col.g * fmin(1, j + lig->rat * i * vtx->col.g / 255);
	res.b = lig->col.b * fmin(1, j + lig->rat * i * vtx->col.b / 255);
	return (res);
}
