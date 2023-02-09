/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmpmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:36:01 by alfux             #+#    #+#             */
/*   Updated: 2023/02/09 08:55:19 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static double	ft_tmp(double x, double y)
{
//	return (0.04 * cos(20 * sqrt(pow(x, 2) + pow(y, 2))));
	return (0.03 * cos(20 * y) * sin(20 * x));
}

t_vec	ft_bmpmap(double x, double y)
{
	t_vec	dx;
	t_vec	dy;
	double	a;

	a = 0.000001;
	dx = ft_setvec(1, 0, (ft_tmp(x + a, y) - ft_tmp(x - a, y)) / (2 * a));
	dy = ft_setvec(0, 1, (ft_tmp(x, y + a) - ft_tmp(x, y - a)) / (2 * a));
	return (ft_nrmlze(ft_provec(dx, dy)));
}
