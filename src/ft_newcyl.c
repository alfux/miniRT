/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:51:26 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 21:01:37 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_cyl	*ft_newcyl(t_vec pos, t_vec dir, t_vec dh, t_rgb col)
{
	t_cyl	*new;

	new = (t_cyl *)ft_calloc(1, sizeof (t_cyl));
	if (!new)
		return (new);
	new->pos = pos;
	new->dir = dir;
	new->dia = dh.x;
	new->hgt = dh.y;
	new->col = col;
	return (new);
}
