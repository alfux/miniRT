/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysehc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:55 by efunes            #+#    #+#             */
/*   Updated: 2023/02/20 17:54:21 by efunes           ###   ########.fr       */
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
	itr->nml = ft_nrmlze(ft_setvec(itr->nml.x * ehc->rat.x,
				itr->nml.y * ehc->rat.y, itr->nml.z * ehc->rat.z));
//	itr->bmp = ft_ellbmp(&itr->vtx, &itr->nml, ell);
//	itr->col = ft_ellrgb(&itr->vtx, ell);
	itr->spc = ehc->spc;
	return (0);
}

static void	ft_sysehcx(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_ehc const *ehc)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_d;
	double	d_f;

	rat.x = ehc->rat.x;
	rat.y = ehc->rat.y;
	rat.z = ehc->rat.z;
	d_d = dir->x * (ehc->pos.z - pov->z) - dir->z * (ehc->pos.x - pov->x);
	d_f = dir->y * (ehc->pos.x - pov->x) - dir->x * (ehc->pos.y - pov->y);
	sol = ft_polyd2(ft_setvec(rat.x + (pow(dir->z, 2) * rat.z
					+ pow(dir->y, 2) * rat.y) / pow(dir->x, 2),
				2 * pow(1 / dir->x, 2) * (dir->y * d_f * rat.y
					- dir->z * d_d * rat.z),
				(d_d * d_d * rat.z + d_f * d_f * rat.y) / pow(dir->x, 2) - ehc->dia));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec(sol.x, (sol.x * dir->y + d_f)
					/ dir->x, (sol.x * dir->z - d_d) / dir->x), ehc->pos);
	if (ft_lstehc_itr(lst, &res, ehc) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec(sol.y, (sol.y * dir->y + d_f)
					/ dir->x, (sol.y * dir->z - d_d) / dir->x), ehc->pos);
	(void)ft_lstehc_itr(lst, &res, ehc);
}

static void	ft_sysehcy(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_ehc const *ehc)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_f;
	double	d_e;

	rat.x = ehc->rat.x;
	rat.y = ehc->rat.y;
	rat.z = ehc->rat.z;
	d_f = dir->y * (ehc->pos.x - pov->x) - dir->x * (ehc->pos.y - pov->y);
	d_e = dir->z * (ehc->pos.y - pov->y) - dir->y * (ehc->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec(rat.y + (pow(dir->x, 2) * rat.x + pow(dir->z, 2)
					* rat.z) / pow(dir->y, 2),
				2 * pow(1 / dir->y, 2) * (dir->z * d_e * rat.z
					- dir->x * d_f * rat.x),
				(d_e * d_e * rat.z + d_f * d_f * rat.x) / pow(dir->y, 2) - ehc->dia));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir->x - d_f) / dir->y,
					sol.x, (sol.x * dir->z + d_e) / dir->y), ehc->pos);
	if (ft_lstehc_itr(lst, &res, ehc) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir->x - d_f) / dir->y,
					sol.y, (sol.y * dir->z + d_e) / dir->y), ehc->pos);
	(void)ft_lstehc_itr(lst, &res, ehc);
}

static void	ft_sysehcz(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_ehc const *ehc)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_d;
	double	d_e;

	rat.x = ehc->rat.x;
	rat.y = ehc->rat.y;
	rat.z = ehc->rat.z;
	d_d = dir->x * (ehc->pos.z - pov->z) - dir->z * (ehc->pos.x - pov->x);
	d_e = dir->z * (ehc->pos.y - pov->y) - dir->y * (ehc->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec(rat.z + (pow(dir->x, 2) * rat.x  + pow(dir->y, 2)
					* rat.y) / pow(dir->z, 2),
				2 * pow(1 / dir->z, 2) * (dir->x * d_d * rat.x
					- dir->y * d_e * rat.y),
				(d_e * d_e * rat.y + d_d * d_d * rat.x) / pow(dir->z, 2) - ehc->dia));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir->x + d_d) / dir->z,
					(sol.x * dir->y - d_e) / dir->z, sol.x), ehc->pos);
	if (ft_lstehc_itr(lst, &res, ehc) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir->x + d_d) / dir->z,
					(sol.y * dir->y - d_e) / dir->z, sol.y), ehc->pos);
	(void)ft_lstehc_itr(lst, &res, ehc);
}

t_list	*ft_sysehc(t_vec const *dir, t_vec const *pov, t_ehc const *ehc)
{
	double	a;
	double	b;
	double	c;
	double	choice;
	t_list	*lst;

	lst = (void *)0;
	a = fabs(dir->x);
	b = fabs(dir->y);
	c = fabs(dir->z);
	choice = fmax(fmax(a, b), c);
	if (choice < EPSILON)
		return ((void *)0);
	else if (choice == c)
		ft_sysehcz(&lst, dir, pov, ehc);
	else if (choice == b)
		ft_sysehcy(&lst, dir, pov, ehc);
	else if (choice == a)
		ft_sysehcx(&lst, dir, pov, ehc);
	return (lst);
}
