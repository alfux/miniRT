/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:49 by efunes            #+#    #+#             */
/*   Updated: 2023/01/16 19:53:33 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_pars_ell2(t_obj *new, char *str)
{
	if (ft_pars_double(&((t_co *)(new->obj))->dia, &str)
		|| ((t_ell *)(new->obj))->dia < 0)
		return (12);
	if (ft_rgb(&((t_ell *)(new->obj))->col, &str))
		return (5);
	if (*str)
		return (16);
	return (0);
}

int	ft_pars_ell(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'e';
	new->obj = (t_ell *)ft_calloc(1, sizeof (t_ell));
	if (!new->obj)
		return (6 + ft_free(new));
	ft_objadd(obj, new);
	if (ft_coord(&((t_ell *)(new->obj))->pos, &str))
		return (4);
	if (ft_coord(&((t_ell *)(new->obj))->rat, &str)
		|| ((t_ell *)(new->obj))->rat.x <= 0
		|| ((t_ell *)(new->obj))->rat.y <= 0
		|| ((t_ell *)(new->obj))->rat.z <= 0)
		return (16);
	return (ft_pars_ell2(new, str));
}