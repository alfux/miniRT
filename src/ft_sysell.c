/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:55 by efunes            #+#    #+#             */
/*   Updated: 2023/01/23 14:27:31 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_2x3	ft_sysellx(t_vec const *dir, t_vec const *pov, t_ell const *ell)
{
	// t_vec	util;
	t_vec	sol;
	double	d_y;
	double	d_z;
	// t_2x3	res;

(void)pov;
	d_y = dir->x * (ell->pos.z - pov->z) - dir->z * (ell->pos.x - pov->x);
	d_z = dir->y * (ell->pos.x - pov->x) - dir->x * (ell->pos.y - pov->y);
	sol = ft_polyd2(ft_setvec(pow(ell->rat.y * ell->rat.z, 2)
				+ pow(ell->rat.x / dir->x, 2) * (pow(dir->y
						* ell->rat.z, 2) + pow(dir->z * ell->rat.y, 2)),
				2 * pow(ell->rat.x / dir->x, 2) * (dir->y * d_y
					* pow(ell->rat.z, 2) - dir->z * d_z
					* pow(ell->rat.y, 2)), (d_z * d_z + d_y * d_y)
					/ pow(dir->x, 2) - pow(ell->rat.x * ell->rat.y
					* ell->rat.z, 2) * ell->dia
		/*pow(ell->rat.y * ell->rat.z, 2)
				+ pow(ell->rat.x / dir->x, 2) * (pow(dir->y
						* ell->rat.z, 2) + pow(dir->z * ell->rat.y, 2)),
				2 * pow(ell->rat.x, 2) * ((pow(dir->y * ell->rat.z, 2)
						+ pow(dir->z * ell->rat.y, 2)) / pow(dir->x, 2)
					* (ell->pos.x - pov->x) + (dir->y / dir->x
						* pow(ell->rat.z, 2) * (pov->y - ell->pos.y)
						+ pow(ell->rat.y, 2) * dir->z / dir->x * (pov->z
							- ell->pos.z))), pow(ell->rat.x, 2) * (pow(dir->y
						/ dir->x * (ell->pos.x - pov->x) + pov->y - ell->pos.y,
						2) * pow(ell->rat.z, 2) + pow(dir->z / dir->x
						* (ell->pos.x - pov->x) + pov->z - ell->pos.z, 2)
					* pow(ell->rat.y, 2)) - pow(ell->rat.x * ell->rat.y
					* ell->rat.z * ell->dia, 2)*/));
	// util.z = dir->z / dir->x * (pov->x - ell->pos.x) + pov->z - ell->pos.z;
	// util.y = dir->y / dir->x * (pov->x - ell->pos.x) + pov->y - ell->pos.y;
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(sol, sol));
	// res.top.x = sol.x;
	// res.top.y = util.y + sol.x * dir->z / dir->x;
	// res.top.z = util.z + sol.x * dir->y / dir->x;
	// res.bot.x = sol.y;
	// res.bot.y = util.y + sol.y * dir->z / dir->x;
	// res.bot.z = util.z + sol.y * dir->y / dir->x;
	return (ft_set2x3(ft_sum_uv(ft_setvec(sol.x, (sol.x * dir->y - d_y)
					/ dir->x, (sol.x * dir->z - d_z) / dir->x/*sol.x, util.y + sol.x * dir->z
					/ dir->x, util.z + sol.x * dir->y / dir->x*/), ell->pos),
				ft_sum_uv(ft_setvec(sol.y, (sol.y * dir->y - d_y)
					/ dir->x, (sol.y * dir->z - d_z) / dir->x/*sol.y, util.y + sol.y * dir->z / dir->x,
				util.z + sol.y * dir->y / dir->x*/), ell->pos)));
	// return (res);
}

static t_2x3	ft_syselly(t_vec const *dir, t_vec const *pov, t_ell const *ell)
{
	t_vec	util;
	t_vec	sol;
	double	d_x;
	double	d_z;
	// t_2x3	res;

(void)pov;
	d_x = dir->y * (ell->pos.x - pov->x) - dir->x * (ell->pos.y - pov->y);
	d_z = dir->z * (ell->pos.y - pov->y) - dir->y * (ell->pos.z - pov->x);
	sol = ft_polyd2(ft_setvec(pow(ell->rat.x * ell->rat.z, 2)
				+ pow(ell->rat.y / dir->y, 2) * (pow(dir->z
						* ell->rat.x, 2) + pow(dir->x * ell->rat.z, 2)),
				2 * pow(ell->rat.y / dir->y, 2) * (dir->z * d_z
					* pow(ell->rat.x, 2) - dir->x * d_x
					* pow(ell->rat.z, 2)), (d_z * d_z + d_x * d_x)
					/ pow(dir->y, 2) - pow(ell->rat.x * ell->rat.y
					* ell->rat.z, 2) * ell->dia
		/*pow(ell->rat.x, 2) * pow(ell->rat.z, 2)
				+ pow(ell->rat.y, 2) / pow(dir->y, 2) * (pow(dir->x, 2)
					* pow(ell->rat.z, 2) + pow(dir->z, 2) * pow(ell->rat.x, 2)),
				2 * pow(ell->rat.y, 2) * ((pow(dir->x, 2) * pow(ell->rat.z, 2)
						+ pow(dir->z, 2) * pow(ell->rat.x, 2)) / pow(dir->y, 2)
					* (ell->pos.y - pov->y) + dir->z / dir->y * (pov->z
						- ell->rat.z) + dir->x / dir->y * pow(ell->rat.z, 2)
					* (pov->x - ell->rat.x)), pow(ell->rat.y, 2) * pow(dir->x
					/ dir->y * (ell->pos.y - pov->y) + pov->x - ell->pos.x, 2)
				* pow(ell->rat.y, 2) + pow(dir->z / dir->y * (ell->pos.y
						- pov->y) + pov->z - ell->rat.z, 2) * pow(ell->rat.x, 2)
				- pow(ell->dia * ell->rat.x * ell->rat.y * ell->rat.z, 2)*/));
	util.x = dir->x / dir->y * (pov->y - ell->pos.y) + pov->x - ell->pos.x;
	util.z = dir->z / dir->y * (pov->y - ell->pos.y) + pov->z - ell->pos.z;
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(sol, sol));
	// res.top.y = sol.x;
	// res.top.x = util.x + sol.x * dir->x / dir->y;
	// res.top.z = util.z + sol.x * dir->z / dir->y;
	// res.bot.y = sol.y;
	// res.bot.x = util.x + sol.y * dir->x / dir->y;
	// res.bot.z = util.z + sol.y * dir->z / dir->y;
	return (ft_set2x3(ft_sum_uv(ft_setvec((sol.x * dir->x - d_x)
					/ dir->y, sol.x, (sol.x * dir->z - d_z) / dir->y/*util.x + sol.x * dir->x / dir->y,
					sol.x, util.z + sol.x * dir->z / dir->y*/), ell->pos),
				ft_sum_uv(ft_setvec((sol.y * dir->x - d_x)
					/ dir->y, sol.y, (sol.y * dir->z - d_z) / dir->y/*util.x + sol.y * dir->x / dir->y, sol.y,
						util.z + sol.y * dir->z / dir->y*/), ell->pos)));
	// return (res);
}

static t_2x3	ft_sysellz(t_vec const *dir, t_vec const *pov, t_ell const *ell)
{
	t_vec	util;
	t_vec	sol;
	double	d_x;
	double	d_y;
	// t_2x3	res;

(void)pov;
	d_x = dir->x * (ell->pos.z - pov->z) - dir->z * (ell->pos.x - pov->x);
	d_y = dir->z * (ell->pos.y - pov->y) - dir->y * (ell->pos.z - pov->x);
	sol = ft_polyd2(ft_setvec(pow(ell->rat.x * ell->rat.y, 2)
				+ pow(ell->rat.z / dir->z, 2) * (pow(dir->x
						* ell->rat.y, 2) + pow(dir->y * ell->rat.x, 2)),
				2 * pow(ell->rat.z / dir->z, 2) * (dir->x * d_x
					* pow(ell->rat.y, 2) - dir->y * d_y
					* pow(ell->rat.x, 2)), (d_y * d_y + d_x * d_x)
					/ pow(dir->z, 2) - pow(ell->rat.x * ell->rat.y
					* ell->rat.z, 2) * ell->dia/*pow(ell->rat.x, 2) * pow(ell->rat.y, 2)
				+ pow(ell->rat.z, 2) / pow(dir->z, 2) * (pow(dir->y, 2)
					* pow(ell->rat.x, 2) + pow(dir->x, 2) * pow(ell->rat.y, 2)),
				2 * pow(ell->rat.z, 2) / pow(dir->z, 2) * (pow(dir->x, 2)
					* pow(ell->rat.y, 2) + pow(dir->y, 2) * pow(ell->rat.x, 2))
				* (ell->pos.z - pov->z) + pow(ell->rat.z, 2) * (2 * dir->x
					/ dir->z * pow(ell->rat.x, 2) * (pov->y - ell->pos.y) + 2
					* dir->x / dir->z * pow(ell->rat.y, 2) * (pov->x
						- ell->pos.x)), pow(dir->x / dir->z * (ell->pos.z
						- pov->z) + pov->x - ell->pos.x, 2) * pow(ell->rat.z, 2)
				* pow(ell->rat.y, 2) + pow(dir->y / dir->z * (ell->pos.z
						- pov->z) + pov->y - ell->pos.y, 2) * pow(ell->rat.x, 2)
				* pow(ell->rat.z, 2) - pow(ell->rat.x * ell->rat.y
					* ell->rat.z * ell->dia, 2)*/));
	util.x = dir->z / dir->x * (pov->x - ell->pos.x) + pov->z - ell->pos.z;
	util.y = dir->y / dir->x * (pov->x - ell->pos.x) + pov->y - ell->pos.y;
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(sol, sol));
	// res.top.z = sol.x;
	// res.top.y = util.y + sol.x * dir->y / dir->z;
	// res.top.x = util.x + sol.x * dir->x / dir->z;
	// res.bot.z = sol.y;
	// res.bot.y = util.y + sol.y * dir->y / dir->z;
	// res.bot.x = util.x + sol.y * dir->x / dir->z;
	return (ft_set2x3(ft_sum_uv(ft_setvec((sol.x * dir->x - d_x)
					/ dir->z, (sol.x * dir->y - d_y) / dir->z, sol.x/*util.x + sol.x * dir->x / dir->z,
					util.y + sol.x * dir->y / dir->z, sol.x*/), ell->pos),
			ft_sum_uv(ft_setvec((sol.y * dir->x - d_x)
					/ dir->z, (sol.y * dir->y - d_y) / dir->z, sol.y/*util.x + sol.y * dir->x / dir->z,
					util.y + sol.y * dir->y / dir->z, sol.y*/), ell->pos)));
	// return (res);
}

t_2x3	ft_sysell(t_vec const *dir, t_vec const *pov, t_ell const *ell)
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
		return (ft_sysellz(dir, pov, ell));
	else if (choice == b)
		return (ft_syselly(dir, pov, ell));
	else if (choice == a)
		return (ft_sysellx(dir, pov, ell));
	return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
