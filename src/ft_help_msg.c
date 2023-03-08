/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:24:57 by efunes            #+#    #+#             */
/*   Updated: 2023/03/08 16:30:16 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_cam_msg(t_win const *win, char i)
{
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`o'`l'     decrease/increase FOV");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`i'`k'     increase/decrease ambiant light ratio");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`f'`c'     increase/decrease ambiant light RED");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`g'`v'     increase/decrease ambiant light GREEN");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`h'`b'     increase/decrease ambiant light BLUE");
}
