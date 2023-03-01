/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysehc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:55 by efunes            #+#    #+#             */
/*   Updated: 2023/03/01 15:44:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_lstehc_itr(t_list **lst, t_vec const *res, t_ehc const *ehc)
{
	t_itr	*itr;

	itr = ft_calloc(1, sizeof (t_itr));
	if (!itr || (ft_lstadd_new(lst, itr) && !ft_free(itr)))
	{
		ft_lstclear(lst, &free);
		*lst = (void *)-1;
		return (1);
	}
	itr->vtx = *res;
	itr->nml = ft_dif_uv(*res, ehc->pos);
	itr->nml = ft_nrmlze(ft_multmv(ehc->bas, ft_setvec(itr->nml.x * ehc->rat.x,
					itr->nml.y * ehc->rat.y, itr->nml.z * ehc->rat.z)));
	itr->vtx = ft_multmv(ehc->bas, itr->vtx);
	itr->bmp = ft_ehcbmp(&itr->vtx, &itr->nml, ehc);
	itr->col = ft_ehcrgb(&itr->vtx, &itr->nml, ehc);
	itr->spc = ehc->bns.spc;
	return (0);
}

static void	ft_sysehcx(t_list **lst, t_vec const dir, t_vec const pov,
	t_ehc const *ehc)
{
	t_vec	sol;
	t_vec	res;
	double	d_d;
	double	d_f;

	d_d = dir.x * (ehc->pos.z - pov.z) - dir.z * (ehc->pos.x - pov.x);
	d_f = dir.y * (ehc->pos.x - pov.x) - dir.x * (ehc->pos.y - pov.y);
	sol = ft_polyd2(ft_setvec(ehc->rat.x + (pow(dir.z, 2) * ehc->rat.z
					+ pow(dir.y, 2) * ehc->rat.y) / pow(dir.x, 2),
				2 * pow(1 / dir.x, 2) * (dir.y * d_f * ehc->rat.y
					- dir.z * d_d * ehc->rat.z),
				(d_d * d_d * ehc->rat.z + d_f * d_f * ehc->rat.y)
				/ pow(dir.x, 2) - pow(ehc->dia / 2, 2)));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec(sol.x, (sol.x * dir.y + d_f)
				/ dir.x, (sol.x * dir.z - d_d) / dir.x), ehc->pos);
	if (ft_lstehc_itr(lst, &res, ehc) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec(sol.y, (sol.y * dir.y + d_f)
				/ dir.x, (sol.y * dir.z - d_d) / dir.x), ehc->pos);
	(void)ft_lstehc_itr(lst, &res, ehc);
}

static void	ft_sysehcy(t_list **lst, t_vec const dir, t_vec const pov,
	t_ehc const *ehc)
{
	t_vec	sol;
	t_vec	res;
	double	d_f;
	double	d_e;

	d_f = dir.y * (ehc->pos.x - pov.x) - dir.x * (ehc->pos.y - pov.y);
	d_e = dir.z * (ehc->pos.y - pov.y) - dir.y * (ehc->pos.z - pov.z);
	sol = ft_polyd2(ft_setvec(ehc->rat.y + (pow(dir.x, 2) * ehc->rat.x
					+ pow(dir.z, 2) * ehc->rat.z) / pow(dir.y, 2),
				2 * pow(1 / dir.y, 2) * (dir.z * d_e * ehc->rat.z
					- dir.x * d_f * ehc->rat.x),
				(d_e * d_e * ehc->rat.z + d_f * d_f * ehc->rat.x)
				/ pow(dir.y, 2) - pow(ehc->dia / 2, 2)));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir.x - d_f) / dir.y,
				sol.x, (sol.x * dir.z + d_e) / dir.y), ehc->pos);
	if (ft_lstehc_itr(lst, &res, ehc) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir.x - d_f) / dir.y,
				sol.y, (sol.y * dir.z + d_e) / dir.y), ehc->pos);
	(void)ft_lstehc_itr(lst, &res, ehc);
}

static void	ft_sysehcz(t_list **lst, t_vec const dir, t_vec const pov,
	t_ehc const *ehc)
{
	t_vec	sol;
	t_vec	res;
	double	d_d;
	double	d_e;

	d_d = dir.x * (ehc->pos.z - pov.z) - dir.z * (ehc->pos.x - pov.x);
	d_e = dir.z * (ehc->pos.y - pov.y) - dir.y * (ehc->pos.z - pov.z);
	sol = ft_polyd2(ft_setvec(ehc->rat.z + (pow(dir.x, 2) * ehc->rat.x
					+ pow(dir.y, 2) * ehc->rat.y) / pow(dir.z, 2),
				2 * pow(1 / dir.z, 2) * (dir.x * d_d * ehc->rat.x
					- dir.y * d_e * ehc->rat.y),
				(d_e * d_e * ehc->rat.y + d_d * d_d * ehc->rat.x)
				/ pow(dir.z, 2) - pow(ehc->dia / 2, 2)));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir.x + d_d) / dir.z,
				(sol.x * dir.y - d_e) / dir.z, sol.x), ehc->pos);
	if (ft_lstehc_itr(lst, &res, ehc) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir.x + d_d) / dir.z,
				(sol.y * dir.y - d_e) / dir.z, sol.y), ehc->pos);
	(void)ft_lstehc_itr(lst, &res, ehc);
}

t_list	*ft_sysehc(t_vec const *dir, t_vec const *pov, t_ehc const *ehc)
{
	double	choice;
	t_list	*lst;

	lst = (void *)0;
	choice = fmax(fmax(fabs(dir->x), fabs(dir->y)), fabs(dir->z));
	if (choice < EPSILON)
		return ((void *)0);
	else if (choice == fabs(dir->z))
		ft_sysehcz(&lst, *dir, *pov, ehc);
	else if (choice == fabs(dir->y))
		ft_sysehcy(&lst, *dir, *pov, ehc);
	else if (choice == fabs(dir->x))
		ft_sysehcx(&lst, *dir, *pov, ehc);
	if (ehc->typ == 'e' || lst == (void *)0 || lst == (void *)-1)
		return (lst);
	if (ft_hyphgt(&((t_itr *)lst->content)->vtx, ehc) > ehc->hgt / 2)
	{
		ft_lstrem(&lst, lst);
		if (lst && ft_hyphgt(&((t_itr *)lst->content)->vtx, ehc) > ehc->hgt / 2)
			ft_lstrem(&lst, lst);
	}
	else if (lst->next && ft_hyphgt(&((t_itr *)lst->next->content)->vtx, ehc)
		> ehc->hgt / 2)
		ft_lstrem(&lst, lst->next);
	return (lst);
}
