/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:13:11 by alfux             #+#    #+#             */
/*   Updated: 2022/12/07 20:39:24 by alfux            ###   ########.fr       */
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

static t_vec	ft_closer_to_pov(t_2x3 comp, t_vec pov)
{
	if (ft_distce(comp.top, pov) < ft_distce(comp.bot, pov))
		return (comp.top);
	return (comp.bot);
}

uint32_t	ft_raytra(t_win win, t_vec ray, t_obj *obj)
{
	t_2x3	inter;
	t_vec	vec;
	t_vec	tmp;
	t_rgb	rgb;

	rgb = ft_setrgb(0, 0, 0);
	vec = ft_setvec(NAN, NAN, NAN);
	while (obj)
	{
		inter = ft_sysres(ray, win.scn.cam.pov, obj);
		if (!isnan(inter.top.x) && !isnan(inter.bot.x))
		{
			tmp = ft_closer_to_pov(inter, win.scn.cam.pov);
			if ((isnan(vec.x) && isnan(vec.y) && isnan(vec.z))
				|| ft_distce(tmp, win.scn.cam.pov)
				< ft_distce(vec, win.scn.cam.pov))
			{
				vec = tmp;
				rgb = ft_setrgb(((t_sph *)obj->obj)->col.r,
						((t_sph *)obj->obj)->col.g, ((t_sph *)obj->obj)->col.b);
			}
		}
		obj = obj->next;
	}
	return (rgb.b + (rgb.g << 8) + (rgb.r << 16));
}
