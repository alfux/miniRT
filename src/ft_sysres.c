/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2023/02/15 18:11:50 by alfux            ###   ########.fr       */
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
	else if (obj->type == 'p')
		return (ft_syspbl(dir, pov, (t_pbol *)obj->obj));
	else if (obj->type == 'e')
		return (ft_sysell(dir, pov, (t_ell *)obj->obj));
	else if (obj->type == 'h' || obj->type == 'c')
		return ((void *)0);
	else if (obj->type == 'I')
		return (ft_sysimp(dir, pov, (t_imp *)obj->obj));
	else
		return ((void *)0);
}
