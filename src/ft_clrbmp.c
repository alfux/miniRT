/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clrbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:56:51 by alfux             #+#    #+#             */
/*   Updated: 2023/02/14 19:06:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_clrbmp(void *cid, t_obj *obj)
{
	while (obj)
	{
		if (obj->type == 'S' && ((t_sph *)obj->obj)->bmp.iid)
			mlx_destroy_image(cid, ((t_sph *)obj->obj)->bmp.iid);
		else if (obj->type == 'P' && ((t_pla *)obj->obj)->bmp.iid)
			mlx_destroy_image(cid, ((t_pla *)obj->obj)->bmp.iid);
		else if (obj->type == 'C' && ((t_cyl *)obj->obj)->bmp.iid)
			mlx_destroy_image(cid, ((t_cyl *)obj->obj)->bmp.iid);
		obj = obj->next;
	}
}
