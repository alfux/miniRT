/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:39:55 by alfux             #+#    #+#             */
/*   Updated: 2023/01/24 00:25:33 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_rgb	ft_setrgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb	set;

	set.r = r;
	set.g = g;
	set.b = b;
	return (set);
}
