/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:34:18 by alfux             #+#    #+#             */
/*   Updated: 2022/11/25 22:12:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	ft_exit_failure(t_win *win)
{
	return (ft_exit(win, 1));
}

int	ft_exit_success(t_win *win)
{
	return (ft_exit(win, 0));
}

int	ft_exit(t_win *win, int status)
{
	size_t	i;

	if (!win)
	{
		errno = EINVAL;
		perror("error: ");
	}
	i = 0;
	while ((win->img + i)->iid)
		(void)mlx_destroy_image(win->cid, (win->img + i++)->iid);
	(void)mlx_destroy_window(win->cid, win->wid);
	exit(status);
	return (status);
}
