/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:02:28 by alfux             #+#    #+#             */
/*   Updated: 2023/01/02 17:36:37 by alfux            ###   ########.fr       */
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

static int	ft_additr(t_vec const *itr, t_list **lst)
{
	t_vec	*new;

	new = ft_calloc(1, sizeof (t_vec));
	if (!new || (ft_lstadd_new(lst, new) && !ft_free(new)))
		return (1);
	*new = *itr;
	return (0);
}

static int	ft_isface(t_vec const *itr, t_imp const *imp, size_t i)
{
	t_3x3	m;
	t_vec	bar;

	if (!ft_is_val(itr))
		return (0);
	m = ft_invmat(ft_set3x3(imp->vtx[imp->idx[i].a.v],
			imp->vtx[imp->idx[i].b.v], imp->vtx[imp->idx[i].c.v]));
	bar = ft_multmv(m, *itr);
	if (bar.x < 0 || bar.y < 0 || bar.z < 0)
		return (0);
	return (1);
}

t_list	*ft_sysimp(t_vec const *dir, t_vec const *pov, t_imp const *imp)
{
	t_list	*lst;
	t_2x3	itr;
	t_pla	tri;
	size_t	i;

	i = 0;
	lst = (t_list *)0;
	while ((imp->idx + i)->a.v != (size_t)-1)
	{
		tri = ft_idxpla(imp, i);
		itr = ft_syspla(dir, pov, &tri);
		if (ft_isface(&itr.top, imp, i) && ft_additr(&itr.top, &lst))
			return ((t_list *)(size_t)ft_lstclear_return(&lst, 0));
		++i;
	}
	return (lst);
}
