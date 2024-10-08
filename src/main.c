/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2023/03/08 16:02:41 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_win	window;

	ft_bzero(&window, sizeof (t_win));
	if (argc != 2)
	{
		ft_putstr_fd("Error\nMiniRT take one `.rt' map as argument.\n", 2);
		return (1);
	}
	window = ft_setwin(RESOLUTION, (RESOLUTION * 9) / 16, "miniRT");
	window.scn.amb.rat = -1;
	if (ft_pars(&window, argv[1]))
		return (ft_exit(&window, 1));
	(void)mlx_hook(window.wid, 17, 0L, &ft_exit_success, &window);
	(void)mlx_hook(window.wid, 4, 1L << 2, &ft_mousehook, &window);
	(void)mlx_hook(window.wid, 2, 0L, &ft_keyhook, &window);
	ft_render(&window);
	(void)mlx_loop(window.cid);
	return (0);
}
