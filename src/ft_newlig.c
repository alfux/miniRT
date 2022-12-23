/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:44:12 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 15:10:17 by efunes           ###   ########.fr       */
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

int	ft_pars_light(t_obj **lig, char **str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'L';
	new->obj = (t_lig *)ft_calloc(1, sizeof (t_lig));
	if (!new->obj)
	{
		free(new);
		return (6);
	}
	if (ft_coord(&((t_lig *)(new->obj))->pos, str))
		return (4);
	if (ft_pars_float(&((t_lig *)(new->obj))->rat, str))
		return (7);
	if (ft_rgb(&((t_lig *)(new->obj))->col, str))
		return (5);
	if (**str)
		return (11);
	if (!(*lig))
		*lig = new;
	else
		ft_objadd(lig, new);
	return (0);
}
