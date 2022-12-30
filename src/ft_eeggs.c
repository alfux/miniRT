/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eeggs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:35:39 by alfux             #+#    #+#             */
/*   Updated: 2022/12/29 15:15:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_eeggs(t_cam *cam)
{
	cam->pov = ft_setvec(7.1, -7.9, -4.9);
	cam->dir = ft_setvec(-0.318048, 0.662013, 0.678664);
	cam->fov = (cam->fov * 360) / (2 * M_PI);
	ft_setcam(cam);
}
