/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invmat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:52:46 by alfux             #+#    #+#             */
/*   Updated: 2022/12/13 13:25:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_3x3	ft_invmat(t_3x3 m)
{
	float	det;
	t_3x3	inv;

	det = ft_det3x3(m);
	inv.top = ft_setvec(NAN, NAN, NAN);
	inv = ft_set3x3(inv.top, inv.top, inv.top);
	if (det == 0)
		return (inv);
	inv.top.x = (m.mid.y * m.bot.z - m.bot.y * m.mid.z) / det;
	inv.top.y = (-1) * (m.top.y * m.bot.z - m.bot.y * m.top.z) / det;
	inv.top.z = (m.top.y * m.mid.z - m.mid.y * m.top.z) / det;
	inv.mid.x = (-1) * (m.mid.x * m.bot.z - m.bot.x * m.mid.z) / det;
	inv.mid.y = (m.top.x * m.bot.z - m.bot.x * m.top.z) / det;
	inv.mid.z = (-1) * (m.top.x * m.mid.z - m.mid.x * m.top.z) / det;
	inv.bot.x = (m.mid.x * m.bot.y - m.bot.x * m.mid.y) / det;
	inv.bot.y = (-1) * (m.top.x * m.bot.y - m.bot.x * m.top.y) / det;
	inv.bot.z = (m.top.x * m.mid.y - m.mid.x * m.top.y) / det;
	return (inv);
}
