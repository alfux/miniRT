/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/11/25 22:38:45 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <sys/errno.h>
# include <mlx.h>
# include <libft.h>

//Keycodes
# define K_ESCAPE 53

//Image informations structure
struct					s_img
{
	void	*iid;
	char	*iad;
	int		bpp;
	int		opl;
	int		end;
};
typedef struct s_img	t_img;

//MLX session structure
struct					s_win
{
	void	*cid;
	void	*wid;
	t_img	*img;
};
typedef struct s_win	t_win;

t_win	ft_init_win(int width, int height, char *title, t_img *image_tab);
int		ft_exit_success(t_win *win);
int		ft_exit_failure(t_win *win);
int		ft_exit(t_win *win, int status);
int		ft_keyhook(int kid, t_win *win);

#endif
