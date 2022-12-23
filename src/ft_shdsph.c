/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shdsph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:32:26 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 10:57:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	ft_shdsph(t_win const *win, t_sph const *s, t_vec const *p)
{
	t_vec	*lpos;
	t_vec	n;
	t_vec	ldir;

	lpos = &((t_lig *)win->scn.lig->obj)->pos;
	n = ft_nrmlze(ft_dif_uv(*p, s->pos));
	ldir = ft_nrmlze(ft_dif_uv(*lpos, *p));
	if (ft_clside(p, &win->scn.cam->pov, &n, lpos))
		return (fabs(ft_scalar(ldir, n)));
	return (0);
}
