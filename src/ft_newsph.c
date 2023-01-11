/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:46:58 by alfux             #+#    #+#             */
/*   Updated: 2023/01/11 15:48:03 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_sph	*ft_newsph(double dia, t_vec pos, t_rgb col)
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

int	ft_pars_sph(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'S';
	new->obj = (t_sph *)ft_calloc(1, sizeof (t_sph));
	if (!new->obj)
		return (6 + ft_free(new));
	ft_objadd(obj, new);
	if (ft_coord(&((t_sph *)(new->obj))->pos, &str))
		return (4);
	if (ft_pars_double(&((t_sph *)(new->obj))->dia, &str)
		|| ((t_sph *)(new->obj))->dia < 0)
		return (12);
	if (ft_rgb(&((t_sph *)(new->obj))->col, &str))
		return (5);
	if (*str)
		return (16);
	return (0);
}
