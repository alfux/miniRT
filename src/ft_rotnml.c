/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotnml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:26:27 by alfux             #+#    #+#             */
/*   Updated: 2023/02/09 09:09:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_3x3	ft_rotnml(t_3x3 const *bas, t_vec const *v, double phi)
{
	t_vec	i2;
	t_vec	j2;
	t_vec	k2;
	t_3x3	m;
	t_3x3	rot;

	i2 = ft_setvec(bas->top.z, bas->mid.z, bas->bot.z);
	i2 = ft_nrmlze(ft_provec(*v, i2));
	j2 = ft_nrmlze(ft_provec(*v, i2));
	k2 = ft_nrmlze(*v);
	rot = ft_set3x3(ft_setvec(1, 0, 0), ft_setvec(0, cos(phi), sin(phi)),
			ft_setvec(0, -sin(phi), cos(phi)));
	m = ft_set3x3(i2, j2, k2);
	rot = ft_multmm(ft_multmm(m, rot), ft_invmat(m));
	return (rot);
}
