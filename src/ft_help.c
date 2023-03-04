/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:12:47 by efunes            #+#    #+#             */
/*   Updated: 2023/03/04 12:35:43 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#define HGT 295
#define COL 240

static void	ft_hlp_msg(t_win const *win, char save, char i)
{
	if (save < 4) // camera or object mode
	{
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`up'`down'      rotate x");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`left'`right'   rotate y");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`a'`e'   rotate z");
	}
	if (save < 2) // camera mode
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`o'`l'   decrease/increase FOV");
	else
	{
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`f'`c'   increase/decrease RED");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`g'`v'   increase/decrease GREEN");
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
			0x00ffffff, "`h'`b'   increase/decrease BLUE");
	}
}

static void	ft_help_messages(t_win const *win, char save, char i)
{
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`TAB'   select/next light");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`ESC'   exit");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`left mouse'    select object");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`right mouse'   camera mode");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`z'`s'   move forward/backward");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`q'`d'   move left/right");
	mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 15, 20 * i++,
		0x00ffffff, "`p'`m'   move up/down");
	ft_hlp_msg(win, save, i);
}

static void	ft_static_help(t_img *help, char save, int i)
{
	int	max;

	max = 0;
	if (save == 1)
		max = HGT - 2 * 20;
	else if (save == 5)
		max = HGT - 3 * 20;
	else if (save % 2)
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
}

static int	ft_ini_help(t_win *win, t_img *help)
{
	int	i;

	i = 0;
	help->iid = mlx_new_image(win->wid, COL, HGT);
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
	static int	i = 0;

	if (!win->help.iid)
		i = ft_ini_help(win, &(win->help));
	if (win->hlp != save)
		ft_static_help(&(win->help), win->hlp, i);
	save = win->hlp;
	mlx_put_image_to_window(win->cid, win->wid, win->help.iid,
		RESOLUTION - COL - 20, 0);
	if (save < 2) // mode camera
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Camera mode");
	else if (save < 4) // mode objet
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Object mode");
	else if (save < 6) // mode lumiere
		mlx_string_put(win->cid, win->wid, RESOLUTION - COL - 10, 14,
			0x00ffffff, " `.' for help - Light mode");
	if (save % 2)
		ft_help_messages(win, save, 2);
}

// rajouter mlx_destroy_img dans ft_exit
// ajouter variable 'char hlp' dans t_win
	// initialisé à 0
    // modifier avec les hook 
        // help on = impaire // help off = paire
        // 0-1 camera // 2-3 objet // 4-5 light
// ajouter 't_img help' dans t_win
// appeler ft_help a la fin de chaque render