/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgbtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:10:23 by alfux             #+#    #+#             */
/*   Updated: 2023/01/23 20:41:55 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

uint32_t	ft_rgbtoi(t_rgb rgb)
{
	return (rgb.b + (rgb.g << 8) + (rgb.r << 16) + (0 << 24));
}
