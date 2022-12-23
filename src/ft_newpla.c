/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:48:19 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 16:31:29 by efunes           ###   ########.fr       */
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
	new->dir = ft_nrmlze(dir);
	new->col = col;
	return (new);
}

static int	ft_pars2_pla(char *str, t_obj **obj, t_obj *new)
{
	if (*str)
		return (15);
	if (!(*obj))
		*obj = new;
	else
		ft_objadd(obj, new);
	return (0);
}

int	ft_pars_pla(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'P';
	new->obj = (t_pla *)ft_calloc(1, sizeof (t_pla));
	if (!new->obj)
	{
		free(new);
		return (6);
	}
	if (ft_coord(&((t_pla *)(new->obj))->pos, &str))
		return (4);
	if (ft_coord(&((t_pla *)(new->obj))->dir, &str)
		|| ((t_pla *)(new->obj))->dir.x < 0 || ((t_pla *)(new->obj))->dir.x > 1
		|| ((t_pla *)(new->obj))->dir.y < 0 || ((t_pla *)(new->obj))->dir.y > 1
		|| ((t_pla *)(new->obj))->dir.z < 0 || ((t_pla *)(new->obj))->dir.z > 1)
		return (4);
	((t_pla *)(new->obj))->dir = ft_nrmlze(((t_pla *)(new->obj))->dir);
	if (ft_rgb(&((t_pla *)(new->obj))->col, &str))
		return (5);
	return (ft_pars2_pla(str, obj, new));
}
