/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmpmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:36:01 by alfux             #+#    #+#             */
/*   Updated: 2023/02/14 19:57:25 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec	ft_bmpmap(t_img const *img, double x, double y)
{
	t_vec	dx;
	t_vec	dy;
	double	a;

	a = 0.1;
	dx = ft_setvec(1, 0,
			(ft_bmpimg(img, x + a, y) - ft_bmpimg(img, x - a, y)) / (2 * a));
	dy = ft_setvec(0, 1,
			(ft_bmpimg(img, x, y + a) - ft_bmpimg(img, x, y - a)) / (2 * a));
	return (ft_nrmlze(ft_provec(dx, dy)));
}
