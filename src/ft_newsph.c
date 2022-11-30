/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:46:58 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 17:22:31 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_sph	*ft_newsph(float dia, t_vec pos, t_rgb col)
{
	t_sph	*new;

	new = (t_sph *)ft_calloc(1, sizeof (t_sph));
	if (!new)
		return (new);
	new->dia = dia;
	new->pos = pos;
	new->col = col;
	return (new);
}
