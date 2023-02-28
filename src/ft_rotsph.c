/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotsph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:18 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 15:02:30 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_rotsph(t_sph *sph, t_3x3	rot)
{
	sph->bns.dam.bas = ft_multmm(rot, sph->bns.dam.bas);
	sph->bns.bmp.bas = ft_multmm(rot, sph->bns.bmp.bas);
}
