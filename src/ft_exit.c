/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:34:18 by alfux             #+#    #+#             */
/*   Updated: 2023/03/08 16:09:57 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_exit_failure(t_win *win, char const *msg)
{
	ft_putstr_fd("Error\n", 2);
	perror(msg);
	return (ft_exit(win, 1));
}

int	ft_exit_success(t_win *win)
{
	return (ft_exit(win, 0));
}

int	ft_exit(t_win *win, int status)
{
	if (!win)
	{
		errno = EINVAL;
		perror("Error\n");
		return (1);
	}
	if (win->scr.iid)
		(void)mlx_destroy_image(win->cid, win->scr.iid);
	if (win->help.iid)
		(void)mlx_destroy_image(win->cid, win->help.iid);
	(void)mlx_destroy_window(win->cid, win->wid);
	ft_objclear(&win->scn.lig, &free);
	ft_clrbmp(win->cid, win->scn.obj);
	ft_objclear(&win->scn.obj, &free);
	ft_camclear(&win->scn.cam, &free);
	exit(status);
	return (status);
}
