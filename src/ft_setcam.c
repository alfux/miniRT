/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:42:47 by alfux             #+#    #+#             */
/*   Updated: 2022/12/22 13:46:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static int	ft_sign(float x)
{
	if (x >= 0)
		return (1);
	else
		return (-1);
}

t_cam	ft_setcam(t_vec pov, t_vec dir, unsigned char fov)
{
	t_cam	set;
	float	norm;

	if (dir.x != 0 || dir.z != 0)
	{
		norm = ft_norm(dir);
		set.dir = ft_setvec(dir.x / norm, dir.y / norm, dir.z / norm);
		norm = sqrt(set.dir.x * set.dir.x + set.dir.z * set.dir.z);
		set.hor = ft_setvec(set.dir.z / norm, 0, ((-1) * set.dir.x) / norm);
		set.ver = ft_setvec(((-1) * set.dir.x * set.dir.y) / norm, norm,
				((-1) * set.dir.y * set.dir.z) / norm);
	}
	else if (dir.y != 0)
	{
		set.dir = ft_setvec(0, ft_sign(dir.y), 0);
		set.ver = ft_setvec(0, 0, 1);
		set.hor = ft_setvec(ft_sign((-1) * dir.y), 0, 0);
	}
	else
		ft_bzero(&set, sizeof (t_cam));
	set.pov = pov;
	set.fov = (fov * 2 * M_PI) / 360;
	return (set);
}
