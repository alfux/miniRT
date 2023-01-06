/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:02:28 by alfux             #+#    #+#             */
/*   Updated: 2023/01/05 20:04:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_pla	ft_idxpla(t_imp const *imp, size_t i)
{
	t_pla	pla;

	pla.dir = ft_nrmlze(imp->nml[imp->idx[i].a.n]);
	pla.pos = imp->vtx[imp->idx[i].a.v];
	pla.col = imp->col;
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
	m = ft_set3x3(*a, *b, *c);
	bar = ft_chkmat(&m, itr);
	bar = ft_multmv(ft_invmat(m), bar);
	if (!ft_is_val(&bar) || bar.x < 0 || bar.y < 0 || bar.z < 0)
		return (0);
	return (1);
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
			ft_lstadd_back(&lst, itr);
		else
			ft_lstclear(&itr, &free);
		++i;
	}
	return (lst);
}
