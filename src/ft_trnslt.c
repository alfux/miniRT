/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trnslt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:17:24 by alfux             #+#    #+#             */
/*   Updated: 2023/03/04 15:30:32 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_trnslt(t_obj const *obj, t_vec dir)
{
	if (obj->type == 'S')
		((t_sph *)obj->obj)->pos = ft_sum_uv(((t_sph *)obj->obj)->pos, dir);
	else if (obj->type == 'P')
		((t_pla *)obj->obj)->pos = ft_sum_uv(((t_pla *)obj->obj)->pos, dir);
	else if (obj->type == 'C')
		((t_cyl *)obj->obj)->pos = ft_sum_uv(((t_cyl *)obj->obj)->pos, dir);
	else if (obj->type == 'L')
		((t_lig *)obj->obj)->pos = ft_sum_uv(((t_lig *)obj->obj)->pos, dir);
	else if (obj->type == 'p')
		((t_pbol *)obj->obj)->pos = ft_sum_uv(((t_pbol *)obj->obj)->pos, dir);
	else if (obj->type == 'e' || obj->type == 'h' || obj->type == 'c')
		((t_ehc *)obj->obj)->pos = ft_sum_uv(((t_ehc *)obj->obj)->pos, dir);
	else if (obj->type == 'I')
		((t_imp *)obj->obj)->pos = ft_sum_uv(((t_imp *)obj->obj)->pos, dir);
}
