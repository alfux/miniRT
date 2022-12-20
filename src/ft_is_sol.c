/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:54:58 by alfux             #+#    #+#             */
/*   Updated: 2022/12/20 15:00:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	ft_is_sol(t_2x3 const *itr)
{
	if (isnan(itr->top.x) || isnan(itr->top.y) || isnan(itr->top.z))
		return (0);
	if (isnan(itr->bot.x) || isnan(itr->bot.y) || isnan(itr->bot.z))
		return (0);
	return (1);
}
