/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:55 by efunes            #+#    #+#             */
/*   Updated: 2023/02/13 18:43:28 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_2x3	ft_sysellx(t_vec const *dir, t_vec const *pov, t_ell *ell)
{
	t_vec	sol;
	t_vec	rat;
	double	d_d;
	double	d_f;

	rat.x = pow(1 / ell->rat.x, 2);
	rat.y = pow(1 / ell->rat.y, 2);
	rat.z = -1 * pow(1 / ell->rat.z, 2);
	d_d = dir->x * (ell->pos.z - pov->z) - dir->z * (ell->pos.x - pov->x);
	d_f = dir->y * (ell->pos.x - pov->x) - dir->x * (ell->pos.y - pov->y);
	sol = ft_polyd2(ft_setvec(rat.x + (pow(dir->z, 2) * rat.z
					+ pow(dir->y, 2) * rat.y) / pow(dir->x, 2),
				2 * pow(1 / dir->x, 2) * (dir->y * d_f * rat.y
					- dir->z * d_d * rat.z),
				(d_d * d_d * rat.z + d_f * d_f * rat.y) / pow(dir->x, 2) - ell->dia));
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
	return (ft_set2x3(ft_sum_uv(ft_setvec(sol.x, (sol.x * dir->y + d_f)
					/ dir->x, (sol.x * dir->z - d_d) / dir->x), ell->pos),
			ft_sum_uv(ft_setvec(sol.y, (sol.y * dir->y + d_f)
					/ dir->x, (sol.y * dir->z - d_d) / dir->x), ell->pos)));
}

static t_2x3	ft_syselly(t_vec const *dir, t_vec const *pov, t_ell *ell)
{
	t_vec	sol;
	t_vec	rat;
	double	d_f;
	double	d_e;

	rat.x = pow(1 / ell->rat.x, 2);
	rat.y = pow(1 / ell->rat.y, 2);
	rat.z = -1 * pow(1 / ell->rat.z, 2);
	d_f = dir->y * (ell->pos.x - pov->x) - dir->x * (ell->pos.y - pov->y);
	d_e = dir->z * (ell->pos.y - pov->y) - dir->y * (ell->pos.z - pov->z);
	sol = ft_polyd2(ft_setvec(rat.y + (pow(dir->x, 2) * rat.x + pow(dir->z, 2)
					* rat.z) / pow(dir->y, 2),
				2 * pow(1 / dir->y, 2) * (dir->z * d_e * rat.z
					- dir->x * d_f * rat.x),
				(d_e * d_e * rat.z + d_f * d_f * rat.x) / pow(dir->y, 2) - ell->dia));
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
	return (ft_set2x3(ft_sum_uv(ft_setvec((sol.x * dir->x - d_f) / dir->y,
					sol.x, (sol.x * dir->z + d_e) / dir->y), ell->pos),
			ft_sum_uv(ft_setvec((sol.y * dir->x - d_f) / dir->y, sol.y,
					(sol.y * dir->z + d_e) / dir->y), ell->pos)));
}

static t_2x3	ft_sysellz(t_vec const *dir, t_vec const *pov, t_ell *ell)
{
	t_vec	sol;
	t_vec	rat;
	double	d_d;
	double	d_e;

	d_d = dir->x * (ell->pos.z - pov->z) - dir->z * (ell->pos.x - pov->x);
	d_e = dir->z * (ell->pos.y - pov->y) - dir->y * (ell->pos.z - pov->z);
	rat.x = pow(1 / ell->rat.x, 2);
	rat.y = pow(1 / ell->rat.y, 2);
	rat.z = -1 * pow(1 / ell->rat.z, 2);
	sol = ft_polyd2(ft_setvec(rat.z + (pow(dir->x, 2) * rat.x  + pow(dir->y, 2)
					* rat.y) / pow(dir->z, 2),
				2 * pow(1 / dir->z, 2) * (dir->x * d_d * rat.x
					- dir->y * d_e * rat.y),
				(d_e * d_e * rat.y + d_d * d_d * rat.x) / pow(dir->z, 2) - ell->dia));
	if (isnan(sol.x) || isnan(sol.y))
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
	return (ft_set2x3(ft_sum_uv(ft_setvec((sol.x * dir->x + d_d) / dir->z,
					(sol.x * dir->y - d_e) / dir->z, sol.x), ell->pos),
			ft_sum_uv(ft_setvec((sol.y * dir->x + d_d) / dir->z,
					(sol.y * dir->y - d_e) / dir->z, sol.y), ell->pos)));
}

t_2x3	ft_sysell(t_vec const *dir, t_vec const *pov, t_ell *ell)
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
