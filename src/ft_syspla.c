/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syspla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2022/12/27 19:03:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static t_2x3	ft_sysplax(t_vec const *dir, t_vec const *pov, t_pla const *pla,
					t_3x3 const *m)
{
	t_vec	inter;

	inter = ft_multmv(ft_invmat(*m), ft_setvec(
				ft_scalar(pla->dir, pla->pos),
				dir->z * pov->x - dir->x * pov->z,
				dir->y * pov->x - dir->x * pov->y));
	return (ft_set2x3(inter, inter));
}

static t_2x3	ft_sysplay(t_vec const *dir, t_vec const *pov, t_pla const *pla,
					t_3x3 const *m)
{
	t_vec	inter;

	inter = ft_multmv(ft_invmat(*m), ft_setvec(
				ft_scalar(pla->dir, pla->pos),
				dir->y * pov->x - dir->x * pov->y,
				dir->z * pov->y - dir->y * pov->z));
	return (ft_set2x3(inter, inter));
}

static t_2x3	ft_sysplaz(t_vec const *dir, t_vec const *pov, t_pla const *pla,
					t_3x3 const *m)
{
	t_vec	inter;

	inter = ft_multmv(ft_invmat(*m), ft_setvec(
				ft_scalar(pla->dir, pla->pos),
				dir->z * pov->x - dir->x * pov->z,
				dir->z * pov->y - dir->y * pov->z));
	return (ft_set2x3(inter, inter));
}

static int	ft_choose(t_3x3 const *mx, t_3x3 const *my, t_3x3 const *mz)
{
	float	detx;
	float	dety;
	float	detz;
	float	choice;

	detx = ft_det3x3(*mx);
	dety = ft_det3x3(*my);
	detz = ft_det3x3(*mz);
	choice = fmax(fmax(fabs(detx), fabs(dety)), fabs(detz));
	if (choice == detx)
		return (1);
	if (choice == dety)
		return (2);
	return (3);
}

t_2x3	ft_syspla(t_vec const *dir, t_vec const *pov, t_pla const *pla)
{
	t_3x3	mx;
	t_3x3	my;
	t_3x3	mz;
	int	choice;

	mx.top = pla->dir;
	mx.mid = ft_setvec(dir->z, 0, (-1) * dir->x);
	mx.bot = ft_setvec(dir->y, (-1) * dir->x, 0);
	my.top = pla->dir;
	my.mid = ft_setvec(dir->y, (-1) * dir->x, 0);
	my.bot = ft_setvec(0, dir->z, (-1) * dir->y);
	mz.top = pla->dir;
	mz.mid = ft_setvec(dir->z, 0, (-1) * dir->x);
	mz.bot = ft_setvec(0, dir->z, (-1) * dir->y);
	choice = ft_choose(&mx, &my, &mz);
	if (choice == 1)
		return (ft_sysplax(dir, pov, pla, &mx));
	if (choice == 2)
		return (ft_sysplay(dir, pov, pla, &my));
	if (choice == 3)
		return (ft_sysplaz(dir, pov, pla, &mz));
	return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
