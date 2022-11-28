/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:51:26 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 12:53:33 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_cyl	ft_setcyl(t_vec pos, t_vec n, float dia, float hgt)
{
	t_cyl	set;

	set.pos = pos;
	set.n = n;
	set.dia = dia;
	set.hgt = hgt;
	set.col = ft_setrgb(255, 255, 255);
	return (set);
}
