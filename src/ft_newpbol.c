/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:06:10 by efunes            #+#    #+#             */
/*   Updated: 2023/02/23 15:19:28 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_pars_pbol2(t_win *window, t_obj *new, char *str)
{
	if (ft_coord(&((t_pbol *)(new->obj))->rat, &str))
		return (16);
	if (ft_pars_double(&((t_pbol *)(new->obj))->hgt, &str))
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
	if (ft_coord(&((t_pbol *)new->obj)->pos, &str))
		return (4);
	if (ft_orthonormal_basis(&((t_pbol *)new->obj)->bas, &str))
		return(18);
	return (ft_pars_pbol2(window, new, str));
}
