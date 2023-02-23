/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pblhgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:08:50 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 13:19:21 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_pblhgt(t_vec const *p, t_pbol const *pa)
{
	t_vec	q;
	t_vec	dir;

	q = ft_dif_uv(*p, pa->pos);
	dir = ft_setvec(pa->bas.top.z, pa->bas.mid.z, pa->bas.bot.z);
	return (ft_norm(ft_multlv(ft_scalar(q, dir), dir)));
}
