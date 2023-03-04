/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:08:37 by alfux             #+#    #+#             */
/*   Updated: 2023/03/04 15:34:38 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_rotimp(t_imp *imp, t_3x3 rot)
{
	imp->bas = ft_multmm(rot, imp->bas);
	imp->bns.dam.bas = ft_multmm(rot, imp->bns.dam.bas);
	imp->bns.bmp.bas = ft_multmm(rot, imp->bns.bmp.bas);
}
