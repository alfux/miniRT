/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syspla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:20:20 by alfux             #+#    #+#             */
/*   Updated: 2022/12/24 15:25:02 by alfux            ###   ########.fr       */
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

t_2x3	ft_syspla(t_vec const *dir, t_vec const *pov, t_pla const *pla)
{
	t_3x3	m;
	float	det;

	m.top = pla->dir;
	m.mid = ft_setvec(dir->z, 0, (-1) * dir->x);
	m.bot = ft_setvec(0, dir->z, (-1) * dir->y);
	det = ft_det3x3(m);
	if (fabs(det) > EPSILON)
		return (ft_sysplaz(dir, pov, pla, &m));
	m.top = pla->dir;
	m.mid = ft_setvec(dir->y, (-1) * dir->x, 0);
	m.bot = ft_setvec(0, dir->z, (-1) * dir->y);
	det = ft_det3x3(m);
	if (fabs(det) > EPSILON)
		return (ft_sysplay(dir, pov, pla, &m));
	m.top = pla->dir;
	m.mid = ft_setvec(dir->z, 0, (-1) * dir->x);
	m.bot = ft_setvec(dir->y, (-1) * dir->x, 0);
	det = ft_det3x3(m);
	if (fabs(det) > EPSILON)
		return (ft_sysplax(dir, pov, pla, &m));
	return (ft_set2x3(ft_setvec(NAN, NAN, NAN), ft_setvec(NAN, NAN, NAN)));
}
