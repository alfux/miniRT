/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:52 by alfux             #+#    #+#             */
/*   Updated: 2023/01/11 15:15:20 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rgb	ft_addrgb(t_rgb const *c1, t_rgb const *c2)
{
	uint16_t	r;
	uint16_t	g;
	uint16_t	b;
	uint16_t	max;

	r = c1->r + c2->r;
	g = c1->g + c2->g;
	b = c1->g + c2->b;
	max  = fmax(fmax(r, g), b);
	if (r > 255 || g > 255 || b > 255)
		return (ft_setrgb(r * 255 / max, g * 255 / max, b * 255 / max));
	return (ft_setrgb(r, g, b));
}
