/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shdell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:50:34 by efunes            #+#    #+#             */
/*   Updated: 2023/01/22 10:05:17 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_shdell(t_win const *win, t_ell const *ell, t_vec const *p)
{
	t_vec	*lpos;
	t_vec	n;
	t_vec	ldir;

	lpos = &((t_lig *)win->scn.lig->obj)->pos;
	n = ft_nrmlze(ft_dif_uv(*p, ell->pos));
	ldir = ft_nrmlze(ft_dif_uv(*lpos, *p));
	if (ft_clside(p, &win->scn.cam->pov, &n, lpos))
		return (fabs(ft_scalar(ldir, n)));
	return (0);
}
