/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:48:19 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 12:51:13 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_pla	ft_setpla(t_vec pos, t_vec n, t_rgb col)
{
	t_pla	set;

	set.pos = pos;
	set.n = n;
	set.col = col;
	return (set);
}
