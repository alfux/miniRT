/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:48:19 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 21:01:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_pla	*ft_newpla(t_vec pos, t_vec dir, t_rgb col)
{
	t_pla	*new;

	new = (t_pla *)ft_calloc(1, sizeof (t_pla));
	if (!new)
		return (new);
	new->pos = pos;
	new->dir = dir;
	new->col = col;
	return (new);
}
