/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_det3x3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:58:04 by alfux             #+#    #+#             */
/*   Updated: 2022/12/08 21:02:51 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

float	ft_det3x3(t_3x3 m)
{
	return (m.top.x * (m.mid.y * m.bot.z - m.bot.y * m.mid.z)
		- m.top.y * (m.mid.x * m.bot.z - m.bot.x * m.mid.z)
		+ m.top.z * (m.mid.x * m.bot.y - m.bot.x * m.mid.y));
}
