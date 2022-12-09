/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2022/12/09 12:19:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_sys_sph(t_vec const *dir, t_vec const *pov, t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_2x3	res;

	efg.x = dir->z * pov->y - dir->y * pov->z;
	efg.y = dir->x * pov->z - dir->z * pov->x;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, 2 * (efg.x * dir->y - efg.y * dir->x
					- dir->z * ft_scalar(*dir, sph->pos)), (2 * dir->z
					* (sph->pos.x * efg.y - efg.x * sph->pos.y) + pow(efg.x, 2)
					+ pow(efg.y, 2) - efg.z * pow(dir->z, 2))));
	if (sol.z < EPSILON)
		return (ft_set2x3(sol, sol));
	res.top.z = sol.x;
	res.bot.z = sol.y;
	res.top.y = (efg.x + dir->y * sol.x) / dir->z;
	res.bot.y = (efg.x + dir->y * sol.y) / dir->z;
	res.top.x = (dir->x * sol.x - efg.y) / dir->z;
	res.bot.x = (dir->x * sol.y - efg.y) / dir->z;
	return (res);
}

static t_2x3	ft_sys_pla(t_vec const *dir, t_vec const *pov, t_pla const *pla)
{
	t_3x3	m;
	t_vec	inter;

	m.top = pla->dir;
	m.mid = ft_setvec(dir->z, 0, (-1) * dir->x);
	m.bot = ft_setvec(0, dir->z, (-1) * dir->y);
	inter = ft_multmv(ft_invmat(m), ft_setvec(
				ft_scalar(pla->dir, pla->pos),
				dir->z * pov->x - dir->x * pov->z,
				dir->z * pov->y - dir->y * pov->z));
	return (ft_set2x3(inter, inter));
}

t_2x3	ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj)
{
	if (obj->type == 'S')
		return (ft_sys_sph(dir, pov, (t_sph *)obj->obj));
	else if (obj->type == 'P')
		return (ft_sys_pla(dir, pov, (t_pla *)obj->obj));
	else
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
