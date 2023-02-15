/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylhgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:08:50 by alfux             #+#    #+#             */
/*   Updated: 2023/01/05 15:09:02 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_cylhgt(t_vec const *p, t_cyl const *c)
{
	t_vec	q;

	q = ft_dif_uv(*p, c->pos);
	return (ft_norm(ft_multlv(ft_scalar(q, c->dir), c->dir)));
}
