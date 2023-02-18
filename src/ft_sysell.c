/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:55 by efunes            #+#    #+#             */
/*   Updated: 2023/02/18 02:08:25 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_lstell_itr(t_list **lst, t_vec const *res, t_ell const *ell)
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
	itr->nml = ft_dif_uv(*res, ell->pos);
	itr->nml = ft_nrmlze(ft_setvec(itr->nml.x * ell->rat.x,
				itr->nml.y * ell->rat.y, itr->nml.z * ell->rat.z));
	itr->bmp = ft_ellbmp(&itr->vtx, &itr->nml, ell);
	itr->col = ft_ellrgb(&itr->vtx, ell);
	itr->spc = ell->spc;
	return (0);
}

static void	ft_sysellx(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_ell const *ell)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_d;
	double	d_f;

	rat.x = ell->rat.x;
	rat.y = ell->rat.y;
	rat.z = ell->rat.z;
	d_d = dir->x * (ell->pos.z - pov->z) - dir->z * (ell->pos.x - pov->x);
	d_f = dir->y * (ell->pos.x - pov->x) - dir->x * (ell->pos.y - pov->y);
	sol = ft_polyd2(ft_setvec(rat.x + (pow(dir->z, 2) * rat.z
					+ pow(dir->y, 2) * rat.y) / pow(dir->x, 2),
				2 * pow(1 / dir->x, 2) * (dir->y * d_f * rat.y
					- dir->z * d_d * rat.z),
				(d_d * d_d * rat.z + d_f * d_f * rat.y) / pow(dir->x, 2) - ell->dia));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec(sol.x, (sol.x * dir->y + d_f)
					/ dir->x, (sol.x * dir->z - d_d) / dir->x), ell->pos);
	if (ft_lstell_itr(lst, &res, ell) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec(sol.y, (sol.y * dir->y + d_f)
					/ dir->x, (sol.y * dir->z - d_d) / dir->x), ell->pos);
	(void)ft_lstell_itr(lst, &res, ell);
}

static void	ft_syselly(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_ell const *ell)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_f;
	double	d_e;

	rat.x = ell->rat.x;
	rat.y = ell->rat.y;
	rat.z = ell->rat.z;
	d_f = dir->y * (ell->pos.x - pov->x) - dir->x * (ell->pos.y - pov->y);
	d_e = dir->z * (ell->pos.y - pov->y) - dir->y * (ell->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec(rat.y + (pow(dir->x, 2) * rat.x + pow(dir->z, 2)
					* rat.z) / pow(dir->y, 2),
				2 * pow(1 / dir->y, 2) * (dir->z * d_e * rat.z
					- dir->x * d_f * rat.x),
				(d_e * d_e * rat.z + d_f * d_f * rat.x) / pow(dir->y, 2) - ell->dia));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir->x - d_f) / dir->y,
					sol.x, (sol.x * dir->z + d_e) / dir->y), ell->pos);
	if (ft_lstell_itr(lst, &res, ell) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir->x - d_f) / dir->y,
					sol.y, (sol.y * dir->z + d_e) / dir->y), ell->pos);
	(void)ft_lstell_itr(lst, &res, ell);
}

static void	ft_sysellz(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_ell const *ell)
{
	t_vec	sol;
	t_vec	rat;
	t_vec	res;
	double	d_d;
	double	d_e;

	rat.x = ell->rat.x;
	rat.y = ell->rat.y;
	rat.z = ell->rat.z;
	d_d = dir->x * (ell->pos.z - pov->z) - dir->z * (ell->pos.x - pov->x);
	d_e = dir->z * (ell->pos.y - pov->y) - dir->y * (ell->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec(rat.z + (pow(dir->x, 2) * rat.x  + pow(dir->y, 2)
					* rat.y) / pow(dir->z, 2),
				2 * pow(1 / dir->z, 2) * (dir->x * d_d * rat.x
					- dir->y * d_e * rat.y),
				(d_e * d_e * rat.y + d_d * d_d * rat.x) / pow(dir->z, 2) - ell->dia));
	if (isnan(sol.x))
		return ;
	res = ft_sum_uv(ft_setvec((sol.x * dir->x + d_d) / dir->z,
					(sol.x * dir->y - d_e) / dir->z, sol.x), ell->pos);
	if (ft_lstell_itr(lst, &res, ell) || sol.x == sol.y)
		return ;
	res = ft_sum_uv(ft_setvec((sol.y * dir->x + d_d) / dir->z,
					(sol.y * dir->y - d_e) / dir->z, sol.y), ell->pos);
	(void)ft_lstell_itr(lst, &res, ell);
}

t_list	*ft_sysell(t_vec const *dir, t_vec const *pov, t_ell const *ell)
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
		ft_sysellz(&lst, dir, pov, ell);
	else if (choice == b)
		ft_syselly(&lst, dir, pov, ell);
	else if (choice == a)
		ft_sysellx(&lst, dir, pov, ell);
	return (lst);
}
