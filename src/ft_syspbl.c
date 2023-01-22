/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syspbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:49:35 by efunes            #+#    #+#             */
/*   Updated: 2023/01/22 15:34:20 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_2x3	ft_syspblx(t_vec const *dir, t_vec const *pov, t_pbol const *pbl)
{
	t_vec	ijk;
	t_vec	sol;

	ijk = ft_setvec(dir->x * pbl->dir.x, dir->x
			* pbl->dir.y, dir->x * pbl->dir.z);
	sol = ft_polyd2(ft_setvec(pow(pbl->rat.y, 2) + pow(pbl->rat.x * ijk.y
					/ ijk.x, 2), pow(pbl->rat.x, 2) * (-1 * ijk.z / ijk.x
					* pow(pbl->rat.y, 2) + 2 * ijk.y / ijk.x * (ijk.y
						/ ijk.x * (pbl->pos.x - pov->x) + pov->y - pbl->pos.y)),
				pow(pbl->rat.x, 2) * (pow(ijk.y / ijk.x * (pbl->pos.x - pov->x)
						+ pov->y - pbl->pos.y, 2) - pow(pbl->rat.y, 2)
					* pow(ijk.z / ijk.x * (pbl->pos.x - pov->x) + pov->z
						- pbl->pos.z, 2))));
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(sol, sol));
	return (ft_set2x3(ft_sum_uv(ft_setvec(sol.x / pbl->dir.x,
					(ijk.y / ijk.x * (sol.x + pbl->pos.x - pov->x) + pov->y
						- pbl->pos.y) / pbl->dir.y, (ijk.z / ijk.x * (sol.x
							+ pbl->pos.x - pov->x) + pov->z
						- pbl->pos.z) / pbl->dir.z), pbl->pos),
			ft_sum_uv(ft_setvec(sol.y / pbl->dir.x,
					(ijk.y / ijk.x * (sol.y + pbl->pos.x - pov->x) + pov->y
						- pbl->pos.y) / pbl->dir.y, (ijk.z / ijk.x * (sol.y
							+ pbl->pos.x - pov->x) + pov->z
						- pbl->pos.z) / pbl->dir.z), pbl->pos)));
}

static t_2x3	ft_syspbly(t_vec const *dir, t_vec const *pov, t_pbol const *pbl)
{
	t_vec	ijk;
	t_vec	sol;

	ijk = ft_setvec(dir->x * pbl->dir.x, dir->x
			* pbl->dir.y, dir->x * pbl->dir.z);
	sol = ft_polyd2(ft_setvec(pow(pbl->rat.x, 2) + pow(pbl->rat.y * ijk.x
					/ ijk.y, 2), pow(pbl->rat.y, 2) * (-1 * ijk.z / ijk.y
					* pow(pbl->rat.x, 2) + 2 * ijk.x / ijk.y * (ijk.x
						/ ijk.y * (pbl->pos.y - pov->y) + pov->x - pbl->pos.x)),
				pow(pbl->rat.y, 2) * (pow(ijk.x / ijk.y * (pbl->pos.y - pov->y)
						+ pov->x - pbl->pos.x, 2) - pow(pbl->rat.x, 2)
					* pow(ijk.z / ijk.y * (pbl->pos.y - pov->y) + pov->z
						- pbl->pos.z, 2))));
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(sol, sol));
	return (ft_set2x3(ft_sum_uv(ft_setvec((ijk.x / ijk.y * (sol.x + pbl->pos.y
							- pov->y) + pov->x - pbl->pos.x) / pbl->dir.x,
					sol.x / pbl->dir.y, (ijk.z / ijk.y * (sol.x
							+ pbl->pos.y - pov->y) + pov->z
						- pbl->pos.z) / pbl->dir.z), pbl->pos),
			ft_sum_uv(ft_setvec((ijk.x / ijk.y * (sol.y + pbl->pos.y
							- pov->y) + pov->x - pbl->pos.x) / pbl->dir.x,
					sol.y / pbl->dir.y, (ijk.z / ijk.y * (sol.y
							+ pbl->pos.y - pov->y) + pov->z
						- pbl->pos.z) / pbl->dir.z), pbl->pos)));
}

static t_2x3	ft_syspblz(t_vec const *dir, t_vec const *pov, t_pbol const *pbl)
{
	t_vec	ijk;
	t_vec	sol;

	ijk = ft_setvec(dir->x * pbl->dir.x, dir->x
			* pbl->dir.y, dir->x * pbl->dir.z);
	sol = ft_polyd2(ft_setvec((pow(ijk.x * pbl->rat.y, 2) + pow(ijk.y
						* pbl->rat.x, 2)) / pow(ijk.z, 2), 2 * ((pow(pbl->rat.y
							* ijk.x, 2) + pow(pbl->rat.x * ijk.y, 2))
					/ pow(ijk.z, 2) * (pbl->pos.z - pov->z) + ijk.x / ijk.z
					* pow(pbl->rat.y, 2) * (pov->x - pbl->pos.x) + ijk.y
					/ ijk.z * pow(pbl->rat.y, 2) * (pov->y - pbl->pos.y))
				+ pow(pbl->rat.x * pbl->rat.y, 2), pow(pbl->rat.y, 2)
				* pow(ijk.x / ijk.z * (pbl->pos.z - pov->z) + pov->x
					- pbl->pos.x, 2) + pow(pbl->rat.x, 2)
				* pow(ijk.y / ijk.z * (pbl->pos.z - pov->z) + pov->y
					- pbl->pos.y, 2)));
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(sol, sol));
	return (ft_set2x3(ft_sum_uv(ft_setvec((ijk.x / ijk.z * (sol.x + pbl->pos.z
							- pov->z) + pov->x - pbl->pos.x) / pbl->dir.x,
					(ijk.y / ijk.z * (sol.z + pbl->pos.z - pov->x) + pov->y
						- pbl->pos.y) / pbl->dir.y, sol.x / pbl->dir.z),
				pbl->pos),
			ft_sum_uv(ft_setvec((ijk.x / ijk.z * (sol.x + pbl->pos.z
							- pov->z) + pov->x - pbl->pos.x) / pbl->dir.x,
					(ijk.y / ijk.z * (sol.z + pbl->pos.z - pov->x) + pov->y
						- pbl->pos.y) / pbl->dir.y, sol.x / pbl->dir.z),
				pbl->pos)));
}


t_2x3	ft_syspbl(t_vec const *dir, t_vec const *pov, t_pbol const *pbl)
{
	double	a;
	double	b;
	double	c;
	double	choice;

	a = fabs(dir->x);
	b = fabs(dir->y);
	c = fabs(dir->z);
	choice = fmax(fmax(a, b), c);
	if (choice < EPSILON)
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
	else if (choice == c)
		return (ft_syspblz(dir, pov, pbl));
	else if (choice == b)
		return (ft_syspbly(dir, pov, pbl));
	else if (choice == a)
		return (ft_syspblx(dir, pov, pbl));
	return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
