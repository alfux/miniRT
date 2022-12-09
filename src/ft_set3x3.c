/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set3x3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:45:42 by alfux             #+#    #+#             */
/*   Updated: 2022/12/09 09:41:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_3x3	ft_set3x3(t_vec lft, t_vec mid, t_vec rgt)
{
	t_3x3	mat;

	mat.top.x = lft.x;
	mat.mid.x = lft.y;
	mat.bot.x = lft.z;
	mat.top.y = mid.x;
	mat.mid.y = mid.y;
	mat.bot.y = mid.z;
	mat.top.z = rgt.x;
	mat.mid.z = rgt.y;
	mat.bot.z = rgt.z;
	return (mat);
}
