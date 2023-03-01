/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syspbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:20:15 by efunes            #+#    #+#             */
/*   Updated: 2023/03/01 17:52:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_lstpbl_itr(t_list **lst, t_vec const *res, t_pbol const *pbl)
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
	itr->nml = ft_dif_uv(*res, pbl->pos);
	itr->nml = ft_nrmlze(ft_multmv(pbl->bas, ft_setvec(itr->nml.x * 2
					* pbl->rat.x, itr->nml.y * 2 * pbl->rat.y, -pbl->rat.z)));
	itr->vtx = ft_multmv(pbl->bas, itr->vtx);
	itr->bmp = ft_pblbmp(&itr->vtx, &itr->nml, pbl);
	itr->col = ft_pblrgb(&itr->vtx, pbl);
	itr->spc = pbl->bns.spc;
	return (0);
}

static void	ft_syspblx(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_pbol const *pbl)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_d;
	double	d_f;

	rat.x = pbl->rat.x;
	rat.y = pbl->rat.y;
	rat.z = pbl->rat.z;
	d_d = dir->x * (pbl->pos.z - pov->z) - dir->z * (pbl->pos.x - pov->x);
	d_f = dir->y * (pbl->pos.x - pov->x) - dir->x * (pbl->pos.y - pov->y);
	sol = ft_polyd2(ft_setvec(rat.x + rat.y * pow(dir->y / dir->x, 2), 2 * rat.y
				* dir->y * d_f / pow(dir->x, 2) - rat.z * dir->z / dir->x,
				rat.z * d_d / dir->x + rat.y * d_f * d_f / pow(dir->x, 2)));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec(sol.x, (sol.x * dir->y + d_f)
				/ dir->x, (sol.x * dir->z - d_d) / dir->x), pbl->pos);
	if (ft_lstpbl_itr(lst, &res, pbl) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec(sol.y, (sol.y * dir->y + d_f)
				/ dir->x, (sol.y * dir->z - d_d) / dir->x), pbl->pos);
	(void)ft_lstpbl_itr(lst, &res, pbl);
}

static void	ft_syspbly(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_pbol const *pbl)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_f;
	double	d_e;

	rat.x = pbl->rat.x;
	rat.y = pbl->rat.y;
	rat.z = pbl->rat.z;
	d_f = dir->y * (pbl->pos.x - pov->x) - dir->x * (pbl->pos.y - pov->y);
	d_e = dir->z * (pbl->pos.y - pov->y) - dir->y * (pbl->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec(rat.y + rat.x * pow(dir->x / dir->y, 2),
				-1 * (2 * rat.x * dir->x * d_f / pow(dir->y, 2)
					+ rat.z * dir->z / dir->y), rat.x * pow(d_f / dir->y, 2)
				- rat.z * d_e / dir->y));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir->x - d_f) / dir->y,
				sol.x, (sol.x * dir->z + d_e) / dir->y), pbl->pos);
	if (ft_lstpbl_itr(lst, &res, pbl) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir->x - d_f) / dir->y,
				sol.y, (sol.y * dir->z + d_e) / dir->y), pbl->pos);
	(void)ft_lstpbl_itr(lst, &res, pbl);
}

static void	ft_syspblz(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_pbol const *pbl)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_d;
	double	d_e;

	rat.x = pbl->rat.x;
	rat.y = pbl->rat.y;
	rat.z = pbl->rat.z;
	d_d = dir->x * (pbl->pos.z - pov->z) - dir->z * (pbl->pos.x - pov->x);
	d_e = dir->z * (pbl->pos.y - pov->y) - dir->y * (pbl->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec((rat.x * pow(dir->x, 2) + rat.y * pow(dir->y, 2))
				/ pow(dir->z, 2), 2 / pow(dir->z, 2)
				* (dir->x * d_d * rat.x - dir->y * d_e * rat.y) - rat.z,
				(d_d * d_d * rat.x + d_e * d_e * rat.y) / pow(dir->z, 2)));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir->x + d_d) / dir->z,
				(sol.x * dir->y - d_e) / dir->z, sol.x), pbl->pos);
	if (ft_lstpbl_itr(lst, &res, pbl) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir->x + d_d) / dir->z,
				(sol.y * dir->y - d_e) / dir->z, sol.y), pbl->pos);
	(void)ft_lstpbl_itr(lst, &res, pbl);
}

t_list	*ft_syspbl(t_vec const *dir, t_vec const *pov, t_pbol const *pbl)
{
	double	choice;
	t_list	*lst;

	lst = (void *)0;
	choice = fmax(fmax(fabs(dir->x), fabs(dir->y)), fabs(dir->z));
	if (choice < EPSILON)
		return ((void *)0);
	else if (choice == fabs(dir->z))
		ft_syspblz(&lst, dir, pov, pbl);
	else if (choice == fabs(dir->y))
		ft_syspbly(&lst, dir, pov, pbl);
	else if (choice == fabs(dir->x))
		ft_syspblx(&lst, dir, pov, pbl);
	if (lst == (void *)0 || lst == (void *)-1)
		return (lst);
	if (ft_pblhgt(&((t_itr *)lst->content)->vtx, pbl) > pbl->hgt)
	{
		ft_lstrem(&lst, lst);
		if (lst && ft_pblhgt(&((t_itr *)lst->content)->vtx, pbl) > pbl->hgt)
			ft_lstrem(&lst, lst);
	}
	else if (lst->next
		&& ft_pblhgt(&((t_itr *)lst->next->content)->vtx, pbl) > pbl->hgt)
		ft_lstrem(&lst, lst->next);
	return (lst);
}
