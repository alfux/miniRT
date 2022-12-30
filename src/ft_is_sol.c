/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:54:58 by alfux             #+#    #+#             */
/*   Updated: 2022/12/30 09:28:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	ft_is_sol(t_2x3 const *itr)
{
	if (!ft_is_val(&itr->top) || !ft_is_val(&itr->bot))
		return (0);
	return (1);
}
