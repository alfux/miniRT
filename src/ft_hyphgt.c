/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hyphgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:08:50 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 18:13:28 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_hyphgt(t_vec const *p, t_ehc const *c)
{
	t_vec	q;
	t_vec	dir;

	q = ft_dif_uv(*p, ft_multmv(c->bas, c->pos));
	dir = ft_setvec(c->bas.top.z, c->bas.mid.z, c->bas.bot.z);
	return (ft_norm(ft_multlv(ft_scalar(q, dir), dir)));
}
