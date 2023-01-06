/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deadzn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:52:51 by alfux             #+#    #+#             */
/*   Updated: 2023/01/05 19:01:49 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_deadzn(t_vec const *vec, t_vec const *ctr, double rad)
{
	if (ft_distce(*vec, *ctr) <= rad)
		return (1);
	return (0);
}
