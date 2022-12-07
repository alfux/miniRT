/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set3x3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:45:42 by alfux             #+#    #+#             */
/*   Updated: 2022/12/07 09:47:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_3x3	ft_setmat(t_vec top, t_vec mid, t_vec bot)
{
	t_3x3	mat;

	mat.top = top;
	mat.mid = mid;
	mat.bot = bot;
	return (mat);
}
