/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shdcyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:51:29 by alfux             #+#    #+#             */
/*   Updated: 2022/12/29 00:10:56 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_shdcyl(t_win const *win, t_cyl const *c, t_vec const *p)
{
	t_vec	*lpos;
	t_vec	n;
	t_vec	ldir;
	t_vec	q;

	lpos = &((t_lig *)win->scn.lig->obj)->pos;
	q = ft_dif_uv(*p, c->pos);
	n = ft_nrmlze(ft_dif_uv(q, ft_multlv(ft_scalar(q, c->dir), c->dir)));
	ldir = ft_nrmlze(ft_dif_uv(*lpos, *p));
	if (ft_clside(p, &win->scn.cam->pov, &n, lpos))
		return (fabs(ft_scalar(ldir, n)));
	return (0);
}
