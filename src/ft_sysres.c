/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2023/01/05 19:45:49 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_list	*ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj)
{
	if (obj->type == 'S')
		return (ft_syssph(dir, pov, (t_sph *)obj->obj));
	else if (obj->type == 'P')
		return (ft_syspla(dir, pov, (t_pla *)obj->obj));
	else if (obj->type == 'C')
		return (ft_syscyl(dir, pov, (t_cyl *)obj->obj));
	else if (obj->type == 'I')
		return (ft_sysimp(dir, pov, (t_imp *)obj->obj));
	else
		return ((void *)0);
}
