/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotpla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:02:39 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 15:05:03 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_rotpla(t_pla *pla, t_3x3 rot)
{
	pla->dir = ft_multmv(rot, pla->dir);
	pla->bns.dam.bas = ft_multmm(rot, pla->bns.dam.bas);
	pla->bns.bmp.bas = ft_multmm(rot, pla->bns.bmp.bas);
}
