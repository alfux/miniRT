/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newhbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:50:43 by efunes            #+#    #+#             */
/*   Updated: 2023/01/11 16:53:59 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_pars_hbol(t_obj **obj, char *str)
{
	t_obj	*new;

	new = (t_obj *)ft_calloc(1, sizeof (t_obj));
	if (!new)
		return (6);
	new->type = 'h';
	new->obj = (t_hbol *)ft_calloc(1, sizeof (t_hbol));
	if (!new->obj)
		return (6 + ft_free(new));
	ft_objadd(obj, new);
	if (ft_coord(&((t_hbol *)(new->obj))->pos, &str))
		return (4);
	if (ft_coord(&((t_hbol *)(new->obj))->dir, &str))
		return (4);
	if (ft_coord(&((t_hbol *)(new->obj))->rat, &str))
		return (16);
	if (ft_pars_double(&((t_hbol *)(new->obj))->dia, &str))
		return (12);
	if (ft_rgb(&((t_hbol *)(new->obj))->col, &str))
		return (5);
}
