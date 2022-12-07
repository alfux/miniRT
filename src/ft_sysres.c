/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2022/12/07 18:00:43 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_sysequ_sph(t_vec dir, t_vec pov, t_sph sph)
{
	t_vec	efg;
	t_vec	sol;
	t_2x3	res;

	efg.x = dir.z * pov.y - dir.y * pov.z;
	efg.y = dir.x * pov.z - dir.z * pov.x;
	efg.z = (pow(sph.dia, 2) / 4) - ft_scalar(sph.pos, sph.pos);
	sol = ft_polyd2(ft_setvec(1, 2 * (efg.x * dir.y - efg.y * dir.x
					- dir.z * ft_scalar(dir, sph.pos)), (2 * dir.z
					* (sph.pos.x * efg.y - efg.x * sph.pos.y) + pow(efg.x, 2)
					+ pow(efg.y, 2) - efg.z * pow(dir.z, 2))));
	if (sol.z < 0)
		return (ft_set2x3(sol, sol));
	res.top.z = sol.x;
	res.bot.z = sol.y;
	res.top.y = (efg.x + dir.y * sol.x) / dir.z;
	res.bot.y = (efg.x + dir.y * sol.y) / dir.z;
	res.top.x = (dir.x * sol.x - efg.y) / dir.z;
	res.bot.x = (dir.x * sol.y - efg.y) / dir.z;
	return (res);
}

t_2x3	ft_sysres(t_vec dir, t_vec pov, t_obj *obj)
{
	if (obj->type == 'S')
		return (ft_sysequ_sph(dir, pov, *(t_sph *)obj->obj));
	else
		return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
