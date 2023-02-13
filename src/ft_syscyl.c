/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscyl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:11:03 by alfux             #+#    #+#             */
/*   Updated: 2023/02/13 15:53:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static int	ft_lstcyl_itr(t_list **lst, t_vec res, t_cyl const *cyl)
{
	t_vec	q;
	t_itr	*itr;

	itr = ft_calloc(1, sizeof (t_itr));
	if (!itr || (ft_lstadd_new(lst, itr) && !ft_free(itr)))
	{
		ft_lstclear(lst, &free);
		*lst = (void *)-1;
		return (1);
	}
	q = ft_dif_uv(res, cyl->pos);
	itr->vtx = res;
	itr->nml = ft_nrmlze(ft_dif_uv(q, ft_multlv(ft_scalar(q, cyl->dir),
					cyl->dir)));
	itr->bmp = ft_cylbmp(&itr->vtx, &itr->nml, cyl);
	itr->col = ft_cylrgb(&itr->vtx, cyl);
	itr->spc = cyl->spc;
	return (0);
}

static void	ft_syscylx(t_list **lst, t_vec const *d, t_vec const *p,
	t_cyl const *c)
{
	double	e;
	double	f;
	double	d_s_n;
	double	em_p_fn;
	t_vec	sol;

	e = d->x * (p->y - c->pos.y) - d->y * (p->x - c->pos.x);
	f = d->x * (p->z - c->pos.z) - d->z * (p->x - c->pos.x);
	d_s_n = ft_scalar(*d, c->dir);
	em_p_fn = e * c->dir.y + f * c->dir.z;
	sol = ft_polyd2(ft_setvec(1 - pow(d_s_n, 2),
				2 * (e * d->y + f * d->z - em_p_fn * d_s_n), pow(e, 2)
				+ pow(f, 2) - pow(em_p_fn, 2) - pow(d->x * c->dia / 2, 2)));
	if (isnan(sol.x) && isnan(sol.y) && sol.z < 0.f)
		return ;
	if (ft_lstcyl_itr(lst, ft_sum_uv(ft_setvec(sol.x, (d->y * sol.x + e) / d->x,
					(d->z * sol.x + f) / d->x), c->pos), c) || sol.x == sol.y)
		return ;
	(void)ft_lstcyl_itr(lst, ft_sum_uv(ft_setvec(sol.y, (d->y * sol.y + e)
				/ d->x, (d->z * sol.y + f) / d->x), c->pos), c);
}

static void	ft_syscyly(t_list **lst, t_vec const *d, t_vec const *p,
	t_cyl const *c)
{
	double	e;
	double	f;
	double	d_s_n;
	double	el_p_fn;
	t_vec	sol;

	e = d->y * (p->x - c->pos.x) - d->x * (p->y - c->pos.y);
	f = d->y * (p->z - c->pos.z) - d->z * (p->y - c->pos.y);
	d_s_n = ft_scalar(*d, c->dir);
	el_p_fn = e * c->dir.x + f * c->dir.z;
	sol = ft_polyd2(ft_setvec(1 - pow(d_s_n, 2),
				2 * (e * d->x + f * d->z - el_p_fn * d_s_n), pow(e, 2)
				+ pow(f, 2) - pow(el_p_fn, 2) - pow(d->y * c->dia / 2, 2)));
	if (isnan(sol.x) && isnan(sol.y) && sol.z < 0.f)
		return ;
	if (ft_lstcyl_itr(lst, ft_sum_uv(ft_setvec((d->x * sol.x + e) / d->y, sol.x,
					(d->z * sol.x + f) / d->y), c->pos), c) || sol.x == sol.y)
		return ;
	(void)ft_lstcyl_itr(lst, ft_sum_uv(ft_setvec((d->x * sol.y + e) / d->y,
				sol.y, (d->z * sol.y + f) / d->y), c->pos), c);
}

static void	ft_syscylz(t_list **lst, t_vec const *d, t_vec const *p,
	t_cyl const *c)
{
	double	e;
	double	f;
	double	d_s_n;
	double	el_p_fm;
	t_vec	sol;

	e = d->z * (p->x - c->pos.x) - d->x * (p->z - c->pos.z);
	f = d->z * (p->y - c->pos.y) - d->y * (p->z - c->pos.z);
	d_s_n = ft_scalar(*d, c->dir);
	el_p_fm = e * c->dir.x + f * c->dir.y;
	sol = ft_polyd2(ft_setvec(1 - pow(d_s_n, 2),
				2 * (e * d->x + f * d->y - el_p_fm * d_s_n), pow(e, 2)
				+ pow(f, 2) - pow(el_p_fm, 2) - pow(d->z * c->dia / 2, 2)));
	if (isnan(sol.x) && isnan(sol.y) && sol.z < 0.f)
		return ;
	if (ft_lstcyl_itr(lst, ft_sum_uv(ft_setvec((d->x * sol.x + e) / d->z,
					(d->y * sol.x + f) / d->z, sol.x), c->pos), c)
		|| sol.x == sol.y)
		return ;
	(void)ft_lstcyl_itr(lst, ft_sum_uv(ft_setvec((d->x * sol.y + e) / d->z,
				(d->y * sol.y + f) / d->z, sol.y), c->pos), c);
}

t_list	*ft_syscyl(t_vec const *dir, t_vec const *pov, t_cyl const *cyl)
{
	double	choice;
	t_list	*lst;

	lst = (void *)0;
	choice = fmax(fmax(fabs(dir->x), fabs(dir->y)), fabs(dir->z));
	if (choice < EPSILON)
		return ((void *)0);
	if (choice == fabs(dir->x))
		ft_syscylx(&lst, dir, pov, cyl);
	else if (choice == fabs(dir->y))
		ft_syscyly(&lst, dir, pov, cyl);
	else if (choice == fabs(dir->z))
		ft_syscylz(&lst, dir, pov, cyl);
	if (lst == (void *)0 || lst == (void *)-1)
		return (lst);
	if (ft_cylhgt(&((t_itr *)lst->content)->vtx, cyl) > cyl->hgt / 2)
	{
		ft_lstrem(&lst, lst);
		if (lst && ft_cylhgt(&((t_itr *)lst->content)->vtx, cyl) > cyl->hgt / 2)
			ft_lstrem(&lst, lst);
	}
	else if (lst->next
		&& ft_cylhgt(&((t_itr *)lst->next->content)->vtx, cyl) > cyl->hgt / 2)
		ft_lstrem(&lst, lst->next);
	return (lst);
}
