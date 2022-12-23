/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clside.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:48:02 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 12:01:33 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_clside(t_vec const *i, t_vec const *p, t_vec const *n, t_vec const *l)
{
	if (ft_scalar(ft_dif_uv(*p, *i), *n) * ft_scalar(ft_dif_uv(*l, *i), *n) < 0)
		return (0);
	return (1);
}
