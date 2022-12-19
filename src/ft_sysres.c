/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2022/12/19 19:00:41 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_2x3	ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj)
{
	if (obj->type == 'S')
		return (ft_syssph(dir, pov, (t_sph *)obj->obj));
	else if (obj->type == 'P')
		return (ft_syspla(dir, pov, (t_pla *)obj->obj));
	else if (obj->type == 'C')
		return (ft_syscyl(dir, pov, (t_cyl *)obj->obj));
	else
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
