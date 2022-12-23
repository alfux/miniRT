/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:46:58 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 16:36:20 by efunes           ###   ########.fr       */
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

static int	ft_pars2_sph(char *str, t_obj **obj, t_obj *new)
{
	if (*str)
		return (16);
	if (!(*obj))
		*obj = new;
	else
		ft_objadd(obj, new);
	return (0);
}

int	ft_pars_sph(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'S';
	new->obj = (t_sph *)ft_calloc(1, sizeof (t_sph));
	if (!new->obj)
	{
		free(new);
		return (6);
	}
	if (ft_coord(&((t_sph *)(new->obj))->pos, &str))
		return (4);
	if (ft_pars_float(&((t_cyl *)(new->obj))->dia, &str)
		|| ((t_cyl *)(new->obj))->dia < 0)
		return (12);
	if (ft_rgb(&((t_sph *)(new->obj))->col, &str))
		return (5);
	return (ft_pars2_sph(str, obj, new));
}
