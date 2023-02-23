/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plabmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:42:41 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 16:07:22 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_plabmp(t_vec const *vtx, t_pla const *pla)
{
	t_vec	vec;

	if (ft_det3x3(pla->bns.bmp.bas) == 0.f || !pla->bns.bmp.map.iid)
		return (pla->dir);
	vec = ft_multmv(ft_invmat(pla->bns.bmp.bas), ft_dif_uv(*vtx, pla->pos));
	return (ft_multmv(pla->bns.bmp.bas, ft_bmpmap(&pla->bns.bmp.map,
				&pla->bns.bmp, vec.x, vec.y)));
}
