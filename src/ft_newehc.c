/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newehc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:49 by efunes            #+#    #+#             */
/*   Updated: 2023/02/23 18:15:37 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_pars_ehc2(t_win *window, t_obj *new, char *str, char type)
{
	((t_ehc *)(new->obj))->rat.x = pow(1 / ((t_ehc *)(new->obj))->rat.x, 2);
	((t_ehc *)(new->obj))->rat.y = pow(1 / ((t_ehc *)(new->obj))->rat.y, 2);
	((t_ehc *)(new->obj))->rat.z = pow(1 / ((t_ehc *)(new->obj))->rat.z, 2);
	if (type == 'h' || type == 'c')
		((t_ehc *)(new->obj))->rat.z = -1 * ((t_ehc *)(new->obj))->rat.z;
	if ((type == 'e' || type == 'h')
			&& (ft_pars_double(&((t_ehc *)new->obj)->dia, &str)
				|| ((t_ehc *)(new->obj))->dia < 0))
		return (12);
	else if (type == 'c')
		((t_ehc *)(new->obj))->dia = 0;
	if ((type == 'h' || type == 'c') && ft_pars_double(&((t_ehc *)(new->obj))->hgt, &str))
		return (13);
	if (ft_rgb(&((t_ehc *)(new->obj))->col, &str))
		return (5);
	if (*str)
		return (ft_bonus_param(window, &((t_ehc *)new->obj)->bns, str));
	return (0);
}

int	ft_pars_ehc(t_win *window, t_obj **obj, char *str, char type)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = type;
	new->obj = (t_ehc *)ft_calloc(1, sizeof (t_ehc));
	if (!new->obj)
		return (6 + ft_free(new));
	((t_ehc *)new->obj)->typ = type;
	ft_objadd(obj, new);
	if (ft_coord(&((t_ehc*)new->obj)->pos, &str))
		return (4);
	if (ft_orthonormal_basis(&((t_ehc *)new->obj)->bas, &str))
		return (20);
	((t_ehc *)new->obj)->pos = ft_multmv(ft_invmat(((t_ehc *)new->obj)->bas), ((t_ehc *)new->obj)->pos);
	if (ft_coord(&((t_ehc *)(new->obj))->rat, &str)
		|| ((t_ehc *)(new->obj))->rat.x <= 0
		|| ((t_ehc *)(new->obj))->rat.y <= 0
		|| ((t_ehc *)(new->obj))->rat.z <= 0)
		return (16);
	return (ft_pars_ehc2(window, new, str, type));
}
