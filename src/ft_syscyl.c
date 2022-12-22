/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:11:03 by alfux             #+#    #+#             */
/*   Updated: 2022/12/22 19:02:37 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_syscylx(t_vec const *d, t_vec const *p, t_cyl const *c)
{
	float	e;
	float	f;
	float	d_s_n;
	float	em_p_fn;
	t_vec	sol;

	e = d->x * (p->y - c->pos.y) - d->y * (p->x - c->pos.x);
	f = d->x * (p->z - c->pos.z) - d->z * (p->x - c->pos.x);
	d_s_n = ft_scalar(*d, c->dir);
	em_p_fn = e * c->dir.y + f * c->dir.z;
	sol = ft_polyd2(ft_setvec(1 - pow(d_s_n, 2),
				2 * (e * d->y + f * d->z - em_p_fn * d_s_n), pow(e, 2)
				+ pow(f, 2) - pow(em_p_fn, 2) - pow(d->x * c->dia / 2, 2)));
	if (isnan(sol.x) && isnan(sol.y) && sol.z < 0.f)
		return (ft_set2x3(sol, sol));
	return (ft_set2x3(ft_sum_uv(ft_setvec(sol.x, (d->y * sol.x + e) / d->x,
					(d->z * sol.x + f) / d->x), c->pos),
			ft_sum_uv(ft_setvec(sol.y, (d->y * sol.y + e) / d->x,
					(d->z * sol.y + f) / d->x), c->pos)));
}

static t_2x3	ft_syscyly(t_vec const *d, t_vec const *p, t_cyl const *c)
{
	float	e;
	float	f;
	float	d_s_n;
	float	el_p_fn;
	t_vec	sol;

	e = d->y * (p->x - c->pos.x) - d->x * (p->y - c->pos.y);
	f = d->y * (p->z - c->pos.z) - d->z * (p->y - c->pos.y);
	d_s_n = ft_scalar(*d, c->dir);
	el_p_fn = e * c->dir.x + f * c->dir.z;
	sol = ft_polyd2(ft_setvec(1 - pow(d_s_n, 2),
				2 * (e * d->x + f * d->z - el_p_fn * d_s_n), pow(e, 2)
				+ pow(f, 2) - pow(el_p_fn, 2) - pow(d->y * c->dia / 2, 2)));
	if (isnan(sol.x) && isnan(sol.y) && sol.z < 0.f)
		return (ft_set2x3(sol, sol));
	return (ft_set2x3(ft_sum_uv(ft_setvec((d->x * sol.x + e) / d->y,
					sol.x, (d->z * sol.x + f) / d->y), c->pos),
			ft_sum_uv(ft_setvec((d->x * sol.y + e) / d->y, sol.y,
					(d->z * sol.y + f) / d->y), c->pos)));
}

static t_2x3	ft_syscylz(t_vec const *d, t_vec const *p, t_cyl const *c)
{
	float	e;
	float	f;
	float	d_s_n;
	float	el_p_fm;
	t_vec	sol;

	e = d->z * (p->x - c->pos.x) - d->x * (p->z - c->pos.z);
	f = d->z * (p->y - c->pos.y) - d->y * (p->z - c->pos.z);
	d_s_n = ft_scalar(*d, c->dir);
	el_p_fm = e * c->dir.x + f * c->dir.y;
	sol = ft_polyd2(ft_setvec(1 - pow(d_s_n, 2),
				2 * (e * d->x + f * d->y - el_p_fm * d_s_n), pow(e, 2)
				+ pow(f, 2) - pow(el_p_fm, 2) - pow(d->z * c->dia / 2, 2)));
	if (isnan(sol.x) && isnan(sol.y) && sol.z < 0.f)
		return (ft_set2x3(sol, sol));
	return (ft_set2x3(ft_sum_uv(ft_setvec((d->x * sol.x + e) / d->z,
					(d->y * sol.x + f) / d->z, sol.x), c->pos),
			ft_sum_uv(ft_setvec((d->x * sol.y + e) / d->z,
					(d->y * sol.y + f) / d->z, sol.y), c->pos)));
}

float	ft_height(t_vec const *p, t_cyl const *c)
{
	t_vec	q;

	q = ft_dif_uv(*p, c->pos);
	return (ft_norm(ft_multlv(ft_scalar(q, c->dir), c->dir)));
}

t_2x3	ft_syscyl(t_vec const *dir, t_vec const *pov, t_cyl const *cyl)
{
	float	choose;
	t_2x3	res;

	choose = fmax(fmax(fabs(dir->x), fabs(dir->y)), fabs(dir->z));
	res = ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN));
	if (choose == fabs(dir->x))
		res = ft_syscylx(dir, pov, cyl);
	if (choose == fabs(dir->y))
		res = ft_syscyly(dir, pov, cyl);
	if (choose == fabs(dir->z))
		res = ft_syscylz(dir, pov, cyl);
	if (ft_height(&res.top, cyl) > cyl->hgt / 2)
	{
		if (ft_height(&res.bot, cyl) > cyl->hgt / 2)
			res.bot = ft_setvec(NAN, NAN, NAN);
		res.top = res.bot;
	}
	else if (ft_height(&res.bot, cyl) > cyl->hgt / 2)
		res.bot = res.top;
	return (res);
}
