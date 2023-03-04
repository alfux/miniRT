/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:02:28 by alfux             #+#    #+#             */
/*   Updated: 2023/03/04 17:20:49 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_pla	ft_idxpla(t_imp const *imp, size_t i)
{
	t_pla	pla;
	t_vec	z;

	ft_bzero(&pla, sizeof (t_pla));
	pla.dir = ft_nrmlze(imp->nml[imp->idx[i].a.n]);
	pla.pos = ft_sum_uv(imp->vtx[imp->idx[i].a.v], imp->pos);
	pla.col = imp->col;
	pla.bns = imp->bns;
	z = ft_nrmlze(ft_setvec(pla.bns.dam.bas.top.z, pla.bns.dam.bas.mid.z,
				pla.bns.dam.bas.bot.z));
	if (ft_scalar(pla.dir, z) != 1)
		pla.bns.dam.bas = ft_multmm(ft_rotnml(&pla.bns.dam.bas, &pla.dir,
					-acos(ft_scalar(z, pla.dir))), pla.bns.dam.bas);
	z = ft_nrmlze(ft_setvec(pla.bns.bmp.bas.top.z, pla.bns.bmp.bas.mid.z,
				pla.bns.bmp.bas.bot.z));
	if (ft_scalar(pla.dir, z) != 1)
		pla.bns.bmp.bas = ft_multmm(ft_rotnml(&pla.bns.bmp.bas, &pla.dir,
					-acos(ft_scalar(z, pla.dir))), pla.bns.bmp.bas);
	return (pla);
}

static t_vec	ft_chkmat(t_3x3 *m, t_vec const *itr)
{
	t_3x3	sav;

	if (ft_det3x3(*m) != 0.)
		return (*itr);
	sav = *m;
	m->top = ft_setvec(1, 1, 1);
	if (ft_det3x3(*m) != 0.)
		return (ft_setvec(1, itr->y, itr->z));
	*m = sav;
	m->mid = ft_setvec(1, 1, 1);
	if (ft_det3x3(*m) != 0.)
		return (ft_setvec(itr->x, 1, itr->z));
	*m = sav;
	m->bot = ft_setvec(1, 1, 1);
	return (ft_setvec(itr->x, itr->y, 1));
}

static int	ft_isface(t_vec const *itr, t_imp const *imp, size_t i)
{
	t_vec	bar;
	t_vec	*a;
	t_vec	*b;
	t_vec	*c;
	t_3x3	m;

	if (!ft_is_val(itr))
		return (0);
	a = &imp->vtx[imp->idx[i].a.v];
	b = &imp->vtx[imp->idx[i].b.v];
	c = &imp->vtx[imp->idx[i].c.v];
	m = ft_set3x3(ft_sum_uv(*a, imp->pos), ft_sum_uv(*b, imp->pos),
			ft_sum_uv(*c, imp->pos));
	bar = ft_chkmat(&m, itr);
	bar = ft_multmv(ft_invmat(m), bar);
	if (!ft_is_val(&bar) || bar.x < 0 || bar.y < 0 || bar.z < 0)
		return (0);
	return (1);
}

void	ft_canon(t_itr *itr, t_imp const *imp)
{
	itr->vtx = ft_multmv(imp->bas, itr->vtx);
	itr->nml = ft_multmv(imp->bas, itr->nml);
	itr->bmp = ft_multmv(imp->bas, itr->bmp);
}

t_list	*ft_sysimp(t_vec const *dir, t_vec const *pov, t_imp const *imp)
{
	t_list	*lst;
	t_list	*itr;
	t_pla	tri;
	size_t	i;

	i = 0;
	lst = (t_list *)0;
	while ((imp->idx + i)->a.v != (size_t)-1)
	{
		tri = ft_idxpla(imp, i);
		itr = ft_syspla(dir, pov, &tri);
		if (itr == (void *)-1)
			return ((void *)(size_t)ft_lstclear_return(&lst, -1));
		if (itr && ft_isface(&((t_itr *)itr->content)->vtx, imp, i))
		{
			ft_canon(itr->content, imp);
			ft_lstadd_back(&lst, itr);
		}
		else
			ft_lstclear(&itr, &free);
		++i;
	}
	return (lst);
}
