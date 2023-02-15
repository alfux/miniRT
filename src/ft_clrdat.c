/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clrdat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:40:23 by alfux             #+#    #+#             */
/*   Updated: 2023/01/11 17:54:57 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_clrdat(t_dat *dat)
{
	ft_lstclear(&dat->v, &free);
	ft_lstclear(&dat->vt, &free);
	ft_lstclear(&dat->vn, &free);
	ft_lstclear(&dat->f, &free);
	return (0);
}
