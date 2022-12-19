/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:11:03 by alfux             #+#    #+#             */
/*   Updated: 2022/12/19 15:23:03 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_syscylx(t_vec const *dir, t_vec const *pov, t_cyl const *cyl)
{
	float	e;
	float	f;
	float	posdir;
	t_vec	sol;
	t_2x3	res;

	e = dir->x * pov->z - dir->z * pov->x;
	f = dir->x * pov->y - dir->y * pov->x;
	posdir = ft_scalar(cyl->pos, cyl->dir);
	sol = ft_polyd2(ft_setvec(1 - pow(ft_scalar(*dir, cyl->dir), 2),
			2 * (dir->z * e + dir->y * f + ft_scalar(*dir,
				ft_dif_uv(ft_multlv(dir->x, ft_dif_uv(ft_multlv(posdir,
				cyl->dir), cyl->pos)), ft_multlv(cyl->dir.z * e + cyl->dir.y
				* f, cyl->dir)))), pow(e - cyl->pos.z * dir->x, 2) + pow(f
				- cyl->pos.y * dir->x, 2) - pow(e * cyl->dir.z + f
				* cyl->dir.y - dir->x * posdir, 2) - pow(dir->x, 2)
				* ((pow(cyl->dia, 2) / 4) - pow(cyl->pos.x, 2))));
	if (isnan(sol.x))
		return (ft_set2x3(sol, sol));
	res.top.x = sol.x;
	res.top.y = (f + dir->y * sol.x) / dir->x;
	res.top.z = (e + dir->z * sol.x) / dir->x;
	res.bot.x = sol.y;
	res.bot.y = (f + dir->y * sol.y) / dir->x;
	res.bot.z = (e + dir->z * sol.y) / dir->x;
	return (res);
}

static t_2x3	ft_syscyly(t_vec const *dir, t_vec const *pov, t_cyl const *cyl)
{
	float	e;
	float	f;
	float	posdir;
	t_vec	sol;
	t_2x3	res;

	e = dir->y * pov->x - dir->x * pov->y;
	f = dir->y * pov->z - dir->z * pov->y;
	posdir = ft_scalar(cyl->pos, cyl->dir);
	sol = ft_polyd2(ft_setvec(1 - pow(ft_scalar(*dir, cyl->dir), 2),
			2 * (dir->x * e + dir->z * f + ft_scalar(*dir,
				ft_dif_uv(ft_multlv(dir->y, ft_dif_uv(ft_multlv(posdir,
				cyl->dir), cyl->pos)), ft_multlv(cyl->dir.x * e + cyl->dir.z
				* f, cyl->dir)))), pow(e - cyl->pos.x * dir->y, 2) + pow(f
				- cyl->pos.z * dir->y, 2) - pow(e * cyl->dir.x + f
				* cyl->dir.z - dir->y * posdir, 2) - pow(dir->y, 2)
				* ((pow(cyl->dia, 2) / 4) - pow(cyl->pos.y, 2))));
	if (isnan(sol.x))
		return (ft_set2x3(sol, sol));
	res.top.y = sol.x;
	res.top.x = (e + dir->x * sol.x) / dir->y;
	res.top.z = (f + dir->z * sol.x) / dir->y;
	res.bot.y = sol.y;
	res.bot.x = (e + dir->x * sol.y) / dir->y;
	res.bot.z = (f + dir->z * sol.y) / dir->y;
	return (res);
}

static t_2x3	ft_syscylz(t_vec const *dir, t_vec const *pov, t_cyl const *cyl)
{
	float	e;
	float	f;
	float	posdir;
	t_vec	sol;
	t_2x3	res;

	e = dir->z * pov->x - dir->x * pov->z;
	f = dir->z * pov->y - dir->y * pov->z;
	posdir = ft_scalar(cyl->pos, cyl->dir);
	sol = ft_polyd2(ft_setvec(1 - pow(ft_scalar(*dir, cyl->dir), 2),
			2 * (dir->x * e + dir->y * f + ft_scalar(*dir,
				ft_dif_uv(ft_multlv(dir->z, ft_dif_uv(ft_multlv(posdir,
				cyl->dir), cyl->pos)), ft_multlv(cyl->dir.x * e + cyl->dir.y
				* f, cyl->dir)))), pow(e - cyl->pos.x * dir->z, 2) + pow(f
				- cyl->pos.y * dir->z, 2) - pow(e * cyl->dir.x + f
				* cyl->dir.y - dir->z * posdir, 2) - pow(dir->z, 2)
				* ((pow(cyl->dia, 2) / 4) - pow(cyl->pos.z, 2))));
	if (isnan(sol.x))
		return (ft_set2x3(sol, sol));
	res.top.z = sol.y;
	res.top.y = (f + dir->y * sol.y) / dir->z;
	res.top.x = (e + dir->x * sol.y) / dir->z;
	res.bot.z = sol.y;
	res.bot.y = (f + dir->y * sol.y) / dir->z;
	res.bot.x = (e + dir->x * sol.y) / dir->z;
	return (res);
}

t_2x3	ft_syscyl(t_vec const *dir, t_vec const *pov, t_cyl const *cyl)
{
	if (dir->z > EPSILON || dir->z < -EPSILON)
		return (ft_syscylz(dir, pov, cyl));
	if (dir->y > EPSILON || dir->y < -EPSILON)
		return (ft_syscyly(dir, pov, cyl));
	if (dir->x > EPSILON || dir->x < -EPSILON)
		return (ft_syscylx(dir, pov, cyl));
	return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
