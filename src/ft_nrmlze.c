/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrmlze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:15 by alfux             #+#    #+#             */
/*   Updated: 2022/12/29 00:03:23 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_vec	ft_nrmlze(t_vec v)
{
	double	norm;

	norm = ft_norm(v);
	return (ft_setvec(v.x / norm, v.y / norm, v.z / norm));
}
