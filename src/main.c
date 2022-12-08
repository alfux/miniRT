/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2022/12/08 12:31:02 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>
#define RADIUS 0.5f
#define COORD 0.0f
#define RESOLUTION 1280

int	main(void)
{
	t_win	window;
	void	*buf;
	void	*tmp;

	window = ft_setwin(RESOLUTION, (RESOLUTION * 9) / 16, "miniRT");
	window.scn.cam = ft_setcam(ft_setvec(2, 2, 2), ft_setvec(-1, -1, -1), 90);
	window.scn.amb = ft_setamb(0.1f, ft_setrgb(255, 255, 255));
	buf = ft_newlig(ft_setvec(2, 0, 0), 1.f, ft_setrgb(255, 255, 255));
	if (!buf)
		ft_exit_failure(&window, "error: light");
	window.scn.lig = ft_objnew('L', buf);
	if (!window.scn.lig && !ft_free(buf))
		ft_exit_failure(&window, "error: object list");
	buf = ft_newsph(RADIUS, ft_setvec(0.f, 0.f, COORD), ft_setrgb(255, 0, 0));
	if (!buf)
		ft_exit_failure(&window, "error: sphere");
	tmp = ft_objnew('S', buf);
	if (!tmp && !ft_free(buf))
		ft_exit_failure(&window, "error: object list");
	ft_objadd(&window.scn.obj, tmp);
	buf = ft_newsph(RADIUS, ft_setvec(0.5f, COORD, 0.f), ft_setrgb(0, 255, 0));
	if (!buf)
		ft_exit_failure(&window, "error: sphere");
	tmp = ft_objnew('S', buf);
	if (!tmp && !ft_free(buf))
		ft_exit_failure(&window, "error: sphere");
	ft_objadd(&window.scn.obj, tmp);
	buf = ft_newsph(RADIUS, ft_setvec(1.f, 0.f, 0.f), ft_setrgb(0, 0, 255));
	if (!buf)
		ft_exit_failure(&window, "error: sphere");
	tmp = ft_objnew('S', buf);
	if (!tmp && !ft_free(buf))
		ft_exit_failure(&window, "error: sphere");
	ft_objadd(&window.scn.obj, tmp);
	(void)mlx_hook(window.wid, 17, 0L, &ft_exit_success, &window);
	(void)mlx_hook(window.wid, 2, 0L, &ft_keyhook, &window);
	ft_render(window);
	(void)mlx_loop(window.cid);
	return (0);
}
