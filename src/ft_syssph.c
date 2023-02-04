/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syssph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2023/02/03 20:12:13 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static int	ft_lstsph_itr(t_list **lst, t_vec const *res, t_sph const *sph)
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
	itr->nml = ft_nrmlze(ft_dif_uv(*res, sph->pos));
	itr->col = ft_sphrgb(res, sph);
	itr->spc = sph->spc;
	return (0);
}

static void	ft_syssphx(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_vec	res;

	efg.x = dir->z * pov->x - dir->x * pov->z;
	efg.y = dir->y * pov->x - dir->x * pov->y;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, (-2) * (efg.y * dir->y + efg.x * dir->z
					+ dir->x * ft_scalar(*dir, sph->pos)), 2 * dir->x
				* (sph->pos.y * efg.y + efg.x * sph->pos.z) + pow(efg.x, 2)
				+ pow(efg.y, 2) - efg.z * pow(dir->x, 2)));
	if (isnan(sol.x))
		return ;
	res.x = sol.x;
	res.y = (dir->y * sol.x - efg.y) / dir->x;
	res.z = (dir->z * sol.x - efg.x) / dir->x;
	if (ft_lstsph_itr(lst, &res, sph) || sol.x == sol.y)
		return ;
	res.x = sol.y;
	res.y = (dir->y * sol.y - efg.y) / dir->x;
	res.z = (dir->z * sol.y - efg.x) / dir->x;
	(void)ft_lstsph_itr(lst, &res, sph);
}

static void	ft_syssphy(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_vec	res;

	efg.x = dir->z * pov->y - dir->y * pov->z;
	efg.y = dir->y * pov->x - dir->x * pov->y;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, 2 * (efg.y * dir->x - efg.x * dir->z
					- dir->y * ft_scalar(*dir, sph->pos)), 2 * dir->y
				* (sph->pos.z * efg.x - efg.y * sph->pos.x) + pow(efg.x, 2)
				+ pow(efg.y, 2) - efg.z * pow(dir->y, 2)));
	if (isnan(sol.x))
		return ;
	res.y = sol.x;
	res.x = (efg.y + dir->x * sol.x) / dir->y;
	res.z = (dir->z * sol.x - efg.x) / dir->y;
	if (ft_lstsph_itr(lst, &res, sph) || sol.x == sol.y)
		return ;
	res.y = sol.y;
	res.x = (efg.y + dir->x * sol.y) / dir->y;
	res.z = (dir->z * sol.y - efg.x) / dir->y;
	(void)ft_lstsph_itr(lst, &res, sph);
}

static void	ft_syssphz(t_list **lst, t_vec const *dir, t_vec const *pov,
	t_sph const *sph)
{
	t_vec	efg;
	t_vec	sol;
	t_vec	res;

	efg.x = dir->z * pov->y - dir->y * pov->z;
	efg.y = dir->x * pov->z - dir->z * pov->x;
	efg.z = (pow(sph->dia, 2) / 4) - ft_scalar(sph->pos, sph->pos);
	sol = ft_polyd2(ft_setvec(1, 2 * (efg.x * dir->y - efg.y * dir->x
					- dir->z * ft_scalar(*dir, sph->pos)), 2 * dir->z
				* (sph->pos.x * efg.y - efg.x * sph->pos.y) + pow(efg.x, 2)
				+ pow(efg.y, 2) - efg.z * pow(dir->z, 2)));
	if (isnan(sol.x))
		return ;
	res.z = sol.x;
	res.y = (efg.x + dir->y * sol.x) / dir->z;
	res.x = (dir->x * sol.x - efg.y) / dir->z;
	if (ft_lstsph_itr(lst, &res, sph) || sol.x == sol.y)
		return ;
	res.z = sol.y;
	res.y = (efg.x + dir->y * sol.y) / dir->z;
	res.x = (dir->x * sol.y - efg.y) / dir->z;
	(void)ft_lstsph_itr(lst, &res, sph);
}

t_list	*ft_syssph(t_vec const *dir, t_vec const *pov, t_sph const *sph)
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
	if (choice == c)
		ft_syssphz(&lst, dir, pov, sph);
	else if (choice == b)
		ft_syssphy(&lst, dir, pov, sph);
	else if (choice == a)
		ft_syssphx(&lst, dir, pov, sph);
	return (lst);
}
