/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotehc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:08:37 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 15:10:42 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_rotehc(t_ehc *ehc, t_3x3 rot)
{
	ehc->bas = ft_multmm(rot, ehc->bas);
	ehc->bns.dam.bas = ft_multmm(rot, ehc->bns.dam.bas);
	ehc->bns.bmp.bas = ft_multmm(rot, ehc->bns.bmp.bas);
}
