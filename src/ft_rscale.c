/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:45 by alfux             #+#    #+#             */
/*   Updated: 2023/03/02 16:07:16 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_hgtscl(t_obj const *obj, double rat)
{
	if (obj->type == 'C')
		((t_cyl *)obj->obj)->hgt *= rat;
	else if (obj->type == 'p')
		((t_pbol *)obj->obj)->hgt *= rat;
	else if (obj->type == 'h')
		((t_ehc *)obj->obj)->hgt *= rat;
	else if (obj->type == 'c')
		((t_ehc *)obj->obj)->hgt *= rat;
}

static void	ft_diascl(t_obj const *obj, double rat)
{
	if (obj->type == 'S')
		((t_sph *)obj->obj)->dia *= rat;
	else if (obj->type == 'C')
		((t_cyl *)obj->obj)->dia *= rat;
	else if (obj->type == 'e')
		((t_ehc *)obj->obj)->dia *= rat;
	else if (obj->type == 'h')
		((t_ehc *)obj->obj)->dia *= rat;
	else if (obj->type == 'L')
		((t_lig *)obj->obj)->rat = fmin(1, ((t_lig *)obj->obj)->rat * rat);
}

void	ft_rscale(int kid, t_obj const *obj)
{
	if (kid == K_I)
		ft_diascl(obj, 1.2);
	else if (kid == K_K)
		ft_diascl(obj, 1 / 1.2);
	else if (kid == K_O)
		ft_hgtscl(obj, 1.2);
	else if (kid == K_L)
		ft_hgtscl(obj, 1 / 1.2);
}
