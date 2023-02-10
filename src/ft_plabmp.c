/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plabmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:42:41 by alfux             #+#    #+#             */
/*   Updated: 2023/02/10 16:53:58 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_plabmp(t_vec const *vtx, t_pla const *pla)
{
	t_vec	vec;

	if (ft_det3x3(pla->bas) == 0.f)
		return (pla->dir);
	vec = ft_multmv(ft_invmat(pla->bas), ft_dif_uv(*vtx, pla->pos));
	return (ft_multmv(pla->bas, ft_bmpmap(vec.x, vec.y)));
}
