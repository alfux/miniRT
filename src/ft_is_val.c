/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:30:08 by alfux             #+#    #+#             */
/*   Updated: 2022/12/29 18:31:55 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_is_val(t_vec const *v)
{
	if (isnan(v->x) || isnan(v->y) || isnan(v->z))
		return (0);
	return (1);
}
