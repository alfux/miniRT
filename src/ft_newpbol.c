/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:06:10 by efunes            #+#    #+#             */
/*   Updated: 2023/02/20 20:01:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_pars_pbol2(t_win *window, t_obj *new, char *str)
{
	if (ft_coord(&((t_pbol *)(new->obj))->rat, &str))
		return (16);
	if (ft_pars_double(&((t_pbol *)(new->obj))->dia, &str))
		return (12);
	if (ft_rgb(&((t_pbol *)(new->obj))->col, &str))
		return (5);
	if (*str)
		return (ft_bonus_param(window, &((t_pbol *)new->obj)->bns, str));
	return (0);
}

int	ft_pars_pbol(t_win *window, t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'p';
	new->obj = (t_pbol *)ft_calloc(1, sizeof (t_pbol));
	if (!new->obj)
		return (6 + ft_free(new));
	ft_objadd(obj, new);
	if (ft_coord(&((t_pbol *)(new->obj))->pos, &str))
		return (4);
	if (ft_coord(&((t_pbol *)(new->obj))->dir, &str)
		|| ((t_pbol *)(new->obj))->dir.x < -1
		|| ((t_pbol *)(new->obj))->dir.x > 1
		|| ((t_pbol *)(new->obj))->dir.y < -1
		|| ((t_pbol *)(new->obj))->dir.y > 1
		|| ((t_pbol *)(new->obj))->dir.z < -1
		|| ((t_pbol *)(new->obj))->dir.z > 1)
		return (4);
	((t_pbol *)(new->obj))->dir = ft_nrmlze(((t_pbol *)(new->obj))->dir);
	return (ft_pars_pbol2(window, new, str));
}
