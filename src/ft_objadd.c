/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:38:10 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 16:52:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

void	ft_objadd(t_obj **obj, t_obj *add)
{
	if (!obj || !add)
		return ;
	while (*obj)
		obj = &(**obj).next;
	*obj = add;
}
