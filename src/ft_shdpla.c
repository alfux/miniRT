/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shdpla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:06:25 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 10:58:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	ft_shdpla(t_win const *win, t_pla const *pl, t_vec const *p)
{
	t_vec	*lpos;
	t_vec	n;
	t_vec	ldir;

	lpos = &((t_lig *)win->scn.lig->obj)->pos;
	n = pl->dir;
	ldir = ft_nrmlze(ft_dif_uv(*lpos, *p));
	if (ft_clside(p, &win->scn.cam->pov, &n, lpos))
		return (fabs(ft_scalar(ldir, n)));
	return (0);
}
