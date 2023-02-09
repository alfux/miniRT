/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multmm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:51:53 by alfux             #+#    #+#             */
/*   Updated: 2023/02/08 00:09:35 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_3x3	ft_multmm(t_3x3 a, t_3x3 b)
{
	return (ft_set3x3(ft_multmv(a, ft_setvec(b.top.x, b.mid.x, b.bot.x)),
			ft_multmv(a, ft_setvec(b.top.y, b.mid.y, b.bot.y)),
			ft_multmv(a, ft_setvec(b.top.z, b.mid.z, b.bot.z))));
}
