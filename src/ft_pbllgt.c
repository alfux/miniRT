/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbllgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:22:09 by alfux             #+#    #+#             */
/*   Updated: 2023/02/28 02:27:32 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_pbllgt(double a, double t)
{
	double	trm1;
	double	trm2;

	trm1 = 2 * t / (a * a);
	trm2 = sqrt(1 + trm1 * trm1);
	return (a * a * (trm1 * trm2 + log(trm1 + trm2)) / 4);
}
