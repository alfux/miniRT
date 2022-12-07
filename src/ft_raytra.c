/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:13:11 by alfux             #+#    #+#             */
/*   Updated: 2022/12/07 12:42:28 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

void	ft_print_inter(t_vec ray, t_sph *sph, t_2x3 inter)
{
	printf("Intersection dir");
	ft_print_vect(ray);
	printf(" on sphere pos");
	ft_print_vect(sph->pos);
	printf(" radius %f are ", sph->dia / 2);
	ft_print_vect(inter.top);
	printf(" and ");
	ft_print_vect(inter.bot);
	printf("\n");
}

uint32_t	ft_raytra(t_win win, t_vec ray, t_obj *obj)
{
	t_2x3	inter;

	while (obj)
	{
		inter = ft_sysres(ray, win.scn.cam.pov, obj);
		if (!isnan(inter.top.x) && !isnan(inter.bot.x))
			return ((((t_sph *)obj->obj)->col.b)
				+ (((t_sph *)obj->obj)->col.g << 8)
				+ (((t_sph *)obj->obj)->col.r << 16));
		obj = obj->next;
	}
	return (0);
}
