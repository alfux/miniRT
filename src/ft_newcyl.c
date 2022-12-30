/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:51:26 by alfux             #+#    #+#             */
/*   Updated: 2022/12/30 13:00:25 by efunes           ###   ########.fr       */
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
	new->dir = ft_nrmlze(dir);
	new->dia = dh.x;
	new->hgt = dh.y;
	new->col = col;
	return (new);
}

static int	ft_pars2_cyl(char *str, t_obj **obj, t_obj *new)
{
	if (ft_pars_double(&((t_cyl *)(new->obj))->hgt, &str))
		return (13);
	if (ft_rgb(&((t_cyl *)(new->obj))->col, &str))
		return (5);
	if (*str)
		return (14);
	if (!(*obj))
		*obj = new;
	else
		ft_objadd(obj, new);
	return (0);
}

int	ft_pars_cyl(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'C';
	new->obj = (t_cyl *)ft_calloc(1, sizeof (t_cyl));
	if (!new->obj)
	{
		free(new);
		return (6);
	}
	if (ft_coord(&((t_cyl *)(new->obj))->pos, &str))
		return (4);
	if (ft_coord(&((t_cyl *)(new->obj))->dir, &str)
		|| ((t_cyl *)(new->obj))->dir.x < -1 || ((t_cyl *)(new->obj))->dir.x > 1
		|| ((t_cyl *)(new->obj))->dir.y < -1 || ((t_cyl *)(new->obj))->dir.y > 1
		|| ((t_cyl *)(new->obj))->dir.z < -1
		|| ((t_cyl *)(new->obj))->dir.z > 1)
		return (4);
	((t_cyl *)(new->obj))->dir = ft_nrmlze(((t_cyl *)(new->obj))->dir);
	if (ft_pars_double(&((t_cyl *)(new->obj))->dia, &str))
		return (12);
	return (ft_pars2_cyl(str, obj, new));
}
