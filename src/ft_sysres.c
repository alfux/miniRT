/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2023/03/04 16:23:47 by afuchs           ###   ########.fr       */
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

static t_list	*ft_pblbas(t_vec const *dir, t_vec const *pov,
	t_pbol const *pbl)
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

static t_list	*ft_impbas(t_vec const *dir, t_vec const *pov,
	t_imp const *imp)
{
	t_vec	dir_bas;
	t_vec	pov_bas;
	t_imp	imp_bas;

	dir_bas = ft_multmv(ft_invmat(imp->bas), *dir);
	pov_bas = ft_multmv(ft_invmat(imp->bas), *pov);
	imp_bas = *imp;
	imp_bas.pos = ft_multmv(ft_invmat(imp->bas), imp->pos);
	return (ft_sysimp(&dir_bas, &pov_bas, &imp_bas));
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
		return (ft_impbas(dir, pov, (t_imp *)obj->obj));
	else
		return ((void *)0);
}
