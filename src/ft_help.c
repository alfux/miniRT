/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:12:47 by efunes            #+#    #+#             */
/*   Updated: 2023/03/04 15:07:06 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_hlp_msg(t_win const *win, char save, char i)
{
	if (save < 4)
	{
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`up'`down'      rotate x");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`left'`right'   rotate y");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`p'`;'          rotate z");
	}
	if (save < 2)
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`o'`l'     decrease/increase FOV");
	else
	{
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`f'`c'     increase/decrease RED");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`g'`v'     increase/decrease GREEN");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`h'`b'     increase/decrease BLUE");
	}
}

static void	ft_help_messages(t_win const *win, char save, char i)
{
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`ESC'      exit");
	if (win->mod)
	{
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`,'        Edition mode");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "``'`1'     prev/next camera");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`TAB'      select/next light");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`left mouse'    select object");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`right mouse'   camera mode");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`w'`s'     move forward/backward");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`a'`d'     move left/right");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`q'`e'     move up/down");
		ft_hlp_msg(win, save, i);
	}
	else
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`,'     Render mode");
}

static void	ft_static_help(t_win *win, t_img *help, char *save, int i)
{
	int	max;

	max = 0;
	if (!win->mod && win->hlp % 2)
		max = 75;
	else if (win->hlp == 1)
		max = HGT - 2 * 20;
	else if (win->hlp == 5)
		max = HGT - 3 * 20;
	else if (win->hlp % 2)
		max = HGT;
	while (help->bpp * i / 8 < help->opl * max)
	{
		*(int *)(help->iad + i * help->bpp / 8) = 0xbb000000;
		i++;
	}
	while (i * help->bpp / 8 < HGT * help->opl)
	{
		*(int *)(help->iad + i * help->bpp / 8) = 0xff000000;
		i++;
	}
	*save = win->hlp;
}

static int	ft_ini_help(t_win *win, t_img *help)
{
	int	i;

	i = 0;
	help->iid = mlx_new_image(win->cid, COL, HGT);
	if (!help->iid)
		ft_error_manager(win, 18, 0);
	help->iad = mlx_get_data_addr(help->iid, &(help->bpp), &(help->opl),
			&(help->end));
	while (i * help->bpp / 8 < 20 * help->opl)
	{
			*(int *)(help->iad + i * help->bpp / 8) = 0x66000000;
			i++;
	}
	return (i);
}

void	ft_help(t_win *win)
{
	static char	save = -1;
	static char	mod = 0;
	static int	i = 0;

	if (!win->help.iid)
		i = ft_ini_help(win, &(win->help));
	if (win->hlp != save || mod != win->mod)
		ft_static_help(win, &(win->help), &save, i);
	mlx_put_image_to_window(win->cid, win->wid, win->help.iid,
		RESOLUTION - COL - 20, 0);
	if (!win->mod)
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Render mode");
	else if (save < 2)
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Edition Camera mode");
	else if (save < 4)
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Edition Object mode");
	else if (save < 6)
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Edition Light mode");
	mod = win->mod;
	if (save % 2)
		ft_help_messages(win, save, 2);
}
