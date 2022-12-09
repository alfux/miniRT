/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multmv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:49:56 by alfux             #+#    #+#             */
/*   Updated: 2022/12/09 09:52:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_vec	ft_multmv(t_3x3 m, t_vec v)
{
	return (ft_setvec(
			ft_scalar(m.top, v), ft_scalar(m.mid, v), ft_scalar(m.bot, v)));
}
