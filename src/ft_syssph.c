/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syssph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2022/12/29 01:02:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_syssphx(t_vec const *dir, t_vec const *pov, t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_2x3	res;

	efg.x = dir->z * pov->x - dir->x * pov->z;
	efg.y = dir->y * pov->x - dir->x * pov->y;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, (-2) * (efg.y * dir->y + efg.x * dir->z
					+ dir->x * ft_scalar(*dir, sph->pos)), 2 * dir->x
				* (sph->pos.y * efg.y + efg.x * sph->pos.z) + pow(efg.x, 2)
				+ pow(efg.y, 2) - efg.z * pow(dir->x, 2)));
	if (isnan(sol.x))
		return (ft_set2x3(sol, sol));
	res.top.x = sol.x;
	res.top.y = (dir->y * sol.x - efg.y) / dir->x;
	res.top.z = (dir->z * sol.x - efg.x) / dir->x;
	res.bot.x = sol.y;
	res.bot.y = (dir->y * sol.y - efg.y) / dir->x;
	res.bot.z = (dir->z * sol.y - efg.x) / dir->x;
	return (res);
}

static t_2x3	ft_syssphy(t_vec const *dir, t_vec const *pov, t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_2x3	res;

	efg.x = dir->z * pov->y - dir->y * pov->z;
	efg.y = dir->y * pov->x - dir->x * pov->y;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, 2 * (efg.y * dir->x - efg.x * dir->z
					- dir->y * ft_scalar(*dir, sph->pos)), 2 * dir->y
				* (sph->pos.z * efg.x - efg.y * sph->pos.x) + pow(efg.x, 2)
				+ pow(efg.y, 2) - efg.z * pow(dir->y, 2)));
	if (isnan(sol.x))
		return (ft_set2x3(sol, sol));
	res.top.y = sol.x;
	res.top.x = (efg.y + dir->x * sol.x) / dir->y;
	res.top.z = (dir->z * sol.x - efg.x) / dir->y;
	res.bot.y = sol.y;
	res.bot.x = (efg.y + dir->x * sol.y) / dir->y;
	res.bot.z = (dir->z * sol.y - efg.x) / dir->y;
	return (res);
}

static t_2x3	ft_syssphz(t_vec const *dir, t_vec const *pov, t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_2x3	res;

	efg.x = dir->z * pov->y - dir->y * pov->z;
	efg.y = dir->x * pov->z - dir->z * pov->x;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, 2 * (efg.x * dir->y - efg.y * dir->x
					- dir->z * ft_scalar(*dir, sph->pos)), 2 * dir->z
				* (sph->pos.x * efg.y - efg.x * sph->pos.y) + pow(efg.x, 2)
				+ pow(efg.y, 2) - efg.z * pow(dir->z, 2)));
	if (isnan(sol.x))
		return (ft_set2x3(sol, sol));
	res.top.z = sol.x;
	res.top.y = (efg.x + dir->y * sol.x) / dir->z;
	res.top.x = (dir->x * sol.x - efg.y) / dir->z;
	res.bot.z = sol.y;
	res.bot.y = (efg.x + dir->y * sol.y) / dir->z;
	res.bot.x = (dir->x * sol.y - efg.y) / dir->z;
	return (res);
}

t_2x3	ft_syssph(t_vec const *dir, t_vec const *pov, t_sph const *sph)
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
	if (choice == c)
		return (ft_syssphz(dir, pov, sph));
	if (choice == b)
		return (ft_syssphy(dir, pov, sph));
	if (choice == a)
		return (ft_syssphx(dir, pov, sph));
	return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
