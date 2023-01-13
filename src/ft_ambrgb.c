/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:51:23 by alfux             #+#    #+#             */
/*   Updated: 2023/01/13 14:14:03 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rgb	ft_ambrgb(t_rgb const *rgb, t_amb const *amb)
{
	t_rgb	res;

	res.r = amb->col.r * amb->rat * rgb->r / 255;
	res.g = amb->col.g * amb->rat * rgb->g / 255;
	res.b = amb->col.b * amb->rat * rgb->b / 255;
	return (res);
}
