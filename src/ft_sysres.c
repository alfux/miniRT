/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2023/01/01 19:44:58 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_lto2x3(t_list *lst)
{
	t_2x3	itr;

	if (!lst)
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
	itr.top = *(t_vec *)lst->content;
	itr.bot = *(t_vec *)lst->content;
	ft_lstclear(&lst, &free);
	return (itr);
}

t_2x3	ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj)
{
	t_2x3	itr;

	if (obj->type == 'S')
		return (ft_syssph(dir, pov, (t_sph *)obj->obj));
	else if (obj->type == 'P')
		return (ft_syspla(dir, pov, (t_pla *)obj->obj));
	else if (obj->type == 'C')
		return (ft_syscyl(dir, pov, (t_cyl *)obj->obj));
	else if (obj->type == 'I')
		itr = ft_lto2x3(ft_sysimp(dir, pov, (t_imp *)obj->obj));
	else
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
	return (itr);
}
