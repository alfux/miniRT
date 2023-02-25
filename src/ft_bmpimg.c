/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmpimg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:13:47 by alfux             #+#    #+#             */
/*   Updated: 2023/02/25 03:12:46 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_bmpimg(t_img const *img, double x, double y)
{
	double	val;

	if (!img || !img->h || !img->w)
		return (0);
	if (x >= img->h - 1 || x < 0)
		x = x - floor(x / (img->h - 1)) * (img->h - 1);
	if (y >= img->w - 1 || y < 0)
		y = y - floor(y / (img->w - 1)) * (img->w - 1);
	val = ((double)(*(uint32_t *)(img->iad + (int)floor(x) * img->opl
		+ (int)floor(y) * img->bpp / 8)) / ((1 << 24) - 1));
	return (val);
}
