/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polyd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:25:09 by alfux             #+#    #+#             */
/*   Updated: 2022/12/21 12:24:49 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_vec	ft_polyd2(t_vec coef)
{
	float	delta;

	delta = (coef.y * coef.y) - (4 * coef.x * coef.z);
	if (delta < 0.f || coef.x == 0.f)
		return (ft_setvec(NAN, NAN, delta));
	return (ft_setvec(((-1) * coef.y + sqrt(delta)) / 2,
			((-1) * coef.y - sqrt(delta)) / 2, delta));
}
