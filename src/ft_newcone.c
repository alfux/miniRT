/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:57:50 by efunes            #+#    #+#             */
/*   Updated: 2023/01/11 17:05:31 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_pars_cone2(t_obj *new, char *str)
{
	if (ft_pars_double(&((t_co *)(new->obj))->dia, &str)
		|| ((t_co *)(new->obj))->dia < 0)
		return (12);
	if (ft_pars_double(&((t_co *)(new->obj))->hgt, &str)
		|| ((t_co *)(new->obj))->dia < 0)
		return (13);
	if (ft_rgb(&((t_co *)(new->obj))->col, &str))
		return (5);
	if (*str)
		return (16);
	return (0);
}

int	ft_pars_cone(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'S';
	new->obj = (t_co *)ft_calloc(1, sizeof (t_co));
	if (!new->obj)
		return (6 + ft_free(new));
	ft_objadd(obj, new);
	if (ft_coord(&((t_co *)(new->obj))->pos, &str))
		return (4);
	if (ft_coord(&((t_co *)(new->obj))->dir, &str)
		|| ((t_co *)(new->obj))->dir.x < -1 || ((t_co *)(new->obj))->dir.x > 1
		|| ((t_co *)(new->obj))->dir.y < -1 || ((t_co *)(new->obj))->dir.y > 1
		|| ((t_co *)(new->obj))->dir.z < -1
		|| ((t_co *)(new->obj))->dir.z > 1)
		return (4);
	((t_co *)(new->obj))->dir = ft_nrmlze(((t_co *)(new->obj))->dir);
	return (ft_pars_cone2(new, str));
}
