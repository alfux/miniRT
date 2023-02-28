/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotcyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:05:41 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 15:08:12 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_rotcyl(t_cyl *cyl, t_3x3 rot)
{
	cyl->dir = ft_multmv(rot, cyl->dir);
	cyl->bns.dam.bas = ft_multmm(rot, cyl->bns.dam.bas);
	cyl->bns.bmp.bas = ft_multmm(rot, cyl->bns.bmp.bas);
}
