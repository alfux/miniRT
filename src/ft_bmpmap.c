/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmpmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:36:01 by alfux             #+#    #+#             */
/*   Updated: 2023/02/14 21:24:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#define RAT 100

t_vec	ft_bmpmap(t_img const *img, double x, double y)
{
	t_vec	dx;
	t_vec	dy;
	double	a;

	a = 1;
	dx = ft_setvec(1, 0,
			(ft_bmpimg(img, RAT * x + a, RAT * y) - ft_bmpimg(img, RAT * x - a, RAT * y)) / (2 * a));
	dy = ft_setvec(0, 1,
			(ft_bmpimg(img, RAT * x, RAT * y + a) - ft_bmpimg(img, RAT * x, RAT * y - a)) / (2 * a));
	return (ft_nrmlze(ft_provec(dx, dy)));
}