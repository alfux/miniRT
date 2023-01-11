/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ligrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:21 by alfux             #+#    #+#             */
/*   Updated: 2023/01/11 14:31:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rgb	ft_rgblig(t_rgb const *rgb, t_lig const *lig, double i)
{
	t_rgb	res;

	res = ft_setrgb(0, 0, 0);
	res.r = fmin(lig->col.r * lig->rat * i, rgb->r);
	res.g = fmin(lig->col.g * lig->rat * i, rgb->g);
	res.b = fmin(lig->col.b * lig->rat * i, rgb->b);
	return (res);
}
