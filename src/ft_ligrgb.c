/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ligrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:21 by alfux             #+#    #+#             */
/*   Updated: 2023/01/13 14:13:23 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rgb	ft_ligrgb(t_rgb const *rgb, t_lig const *lig, double i)
{
	t_rgb	res;

	res.r = lig->col.r * lig->rat * i * rgb->r / 255;
	res.g = lig->col.g * lig->rat * i * rgb->g / 255;
	res.b = lig->col.b * lig->rat * i * rgb->b / 255;
	return (res);
}
