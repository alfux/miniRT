/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2023/02/27 19:40:12 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_list	*ft_ehcbas(t_vec const *dir, t_vec const *pov, t_ehc const *ehc)
{
	t_vec	dir_bas;
	t_vec	pov_bas;
	t_ehc	ehc_bas;

	dir_bas = ft_multmv(ft_invmat(ehc->bas), *dir);
	pov_bas = ft_multmv(ft_invmat(ehc->bas), *pov);
	ehc_bas = *ehc;
	ehc_bas.pos = ft_multmv(ft_invmat(ehc->bas), ehc->pos);
	return (ft_sysehc(&dir_bas, &pov_bas, &ehc_bas));
}

static t_list	*ft_pblbas(t_vec const *dir, t_vec const *pov, t_pbol const *pbl)
{
	t_vec	dir_bas;
	t_vec	pov_bas;
	t_pbol	pbl_bas;

	dir_bas = ft_multmv(ft_invmat(pbl->bas), *dir);
	pov_bas = ft_multmv(ft_invmat(pbl->bas), *pov);
	pbl_bas = *pbl;
	pbl_bas.pos = ft_multmv(ft_invmat(pbl->bas), pbl->pos);
	return (ft_syspbl(&dir_bas, &pov_bas, &pbl_bas));
}

t_list	*ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj)
{
	if (obj->type == 'S')
		return (ft_syssph(dir, pov, (t_sph *)obj->obj));
	else if (obj->type == 'P')
		return (ft_syspla(dir, pov, (t_pla *)obj->obj));
	else if (obj->type == 'C')
		return (ft_syscyl(dir, pov, (t_cyl *)obj->obj));
	else if (obj->type == 'p')
		return (ft_pblbas(dir, pov, (t_pbol *)obj->obj));
	else if (obj->type == 'e' || obj->type == 'h' || obj->type == 'c')
		return (ft_ehcbas(dir, pov, (t_ehc *)obj->obj));
	else if (obj->type == 'I')
		return (ft_sysimp(dir, pov, (t_imp *)obj->obj));
	else
		return ((void *)0);
}
