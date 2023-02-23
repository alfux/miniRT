/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmpmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:36:01 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 17:02:07 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_bmpmap(t_img const *img, t_bmp const *bmp, double x, double y)
{
	t_vec	dx;
	t_vec	dy;
	double	a;

	a = 1;
	dx = ft_setvec(1, 0,
			bmp->relief * (ft_bmpimg(img, bmp->size * x + a, bmp->size * y)
				- ft_bmpimg(img, bmp->size * x - a, bmp->size * y)) / (2 * a));
	dy = ft_setvec(0, 1,
			bmp->relief * (ft_bmpimg(img, bmp->size * x, bmp->size * y + a)
				- ft_bmpimg(img, bmp->size * x, bmp->size * y - a)) / (2 * a));
	return (ft_nrmlze(ft_provec(dx, dy)));
}
