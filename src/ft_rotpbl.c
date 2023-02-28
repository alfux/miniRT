/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotpbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:11:11 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 15:38:42 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_rotpbl(t_pbol *pbl, t_3x3 rot)
{
	pbl->bas = ft_multmm(rot, pbl->bas);
	pbl->bns.dam.bas = ft_multmm(rot, pbl->bns.dam.bas);
	pbl->bns.bmp.bas = ft_multmm(rot, pbl->bns.bmp.bas);
}
