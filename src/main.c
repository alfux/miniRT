/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 12:57:16 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	main(void)
{
	t_win	win;
	t_img	scr;
	size_t	i;
	size_t	j;

	win = ft_setwin(600, 590, "miniRT", &scr);
	scr.iid = mlx_new_image(win.cid, 600, 590);
	scr.iad = mlx_get_data_addr(scr.iid, &scr.bpp, &scr.opl, &scr.end);
	i = -1;
	while (++i < 590)
	{
		j = -1;
		while (++j < 600)
			*(unsigned int *)(scr.iad + i * scr.opl + j * (scr.bpp / 8))
				= (i + j) * ((i + j) % 2) + (i + j) * 256 * ((i + j + 1) % 2);
	}
	mlx_hook(win.wid, 17, 0L, &ft_exit_success, &win);
	mlx_hook(win.wid, 2, 0L, &ft_keyhook, &win);
	mlx_put_image_to_window(win.cid, win.wid, win.scr->iid, 0, 0);
	mlx_loop(win.cid);
	return (0);
}
