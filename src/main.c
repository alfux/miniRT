/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2022/12/03 18:45:23 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	main(void)
{
	t_win	window;
	void	*buf;

	window = ft_setwin(600, 590, "miniRT");
	window.scn.cam = ft_setcam(ft_setvec(0, 0, 0), ft_setvec(0, -13, 0), 90);
	window.scn.amb = ft_setamb(0.1f, ft_setrgb(255, 255, 255));
	buf = ft_newlig(ft_setvec(1, 1, 0), 0.5f, ft_setrgb(255, 255, 255));
	if (!buf)
		ft_exit_failure(&window, "error: light");
	window.scn.lig = ft_objnew('L', buf);
	if (!window.scn.lig && !ft_free(buf))
		ft_exit_failure(&window, "error: object list");
	buf = ft_newsph(0.5f, ft_setvec(0, 0, 0), ft_setrgb(128, 64, 255));
	if (!buf)
		ft_exit_failure(&window, "error: sphere");
	window.scn.obj = ft_objnew('S', buf);
	if (!window.scn.obj && !ft_free(buf))
		ft_exit_failure(&window, "error: object list");
	(void)mlx_hook(window.wid, 17, 0L, &ft_exit_success, &window);
	(void)mlx_hook(window.wid, 2, 0L, &ft_keyhook, &window);
	ft_render(window);
	(void)mlx_loop(window.cid);
	return (0);
}
