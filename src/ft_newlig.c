/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:44:12 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 17:22:41 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_lig	*ft_newlig(t_vec pos, float rat, t_rgb col)
{
	t_lig	*new;

	new = (t_lig *)ft_calloc(1, sizeof (t_lig));
	if (!new)
		return (new);
	new->pos = pos;
	new->rat = rat;
	new->col = col;
	return (new);
}
