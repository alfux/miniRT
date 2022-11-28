/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:42:47 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 12:44:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_cam	ft_setcam(t_vec pov, t_vec n, unsigned char fov)
{
	t_cam	set;

	set.pov = pov;
	set.n = n;
	set.fov = fov;
	return (set);
}
