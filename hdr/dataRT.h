/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/12/24 14:11:58 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATART_H
# define DATART_H

//Keycodes
# define K_ESCAPE 53
# define K_LEFT 123
# define K_UP 126
# define K_RIGHT 124
# define K_DOWN 125
# define K_P 35
# define K_M 41
# define K_Z 13
# define K_Q 0
# define K_S 1
# define K_D 2
# define K_R 15
# define K_T 17
# define K_L 37
# define K_O 31
# define K_SPACE 49

//Constants
# define EPSILON 0.02f

//Vetcor data structure
struct					s_vec
{
	float	x;
	float	y;
	float	z;
};
typedef struct s_vec	t_vec;

//3x3 matrix structure
struct					s_3x3
{
	t_vec	top;
	t_vec	mid;
	t_vec	bot;
};
typedef struct s_3x3	t_3x3;

//2x3 matrix structure
struct					s_2x3
{
	t_vec	top;
	t_vec	bot;
};
typedef struct s_2x3	t_2x3;

//Color data structure
struct					s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};
typedef struct s_rgb	t_rgb;

//Ambiant light data structure
struct					s_amb
{
	float	rat;
	t_rgb	col;
};
typedef struct s_amb	t_amb;

//Camera data structure
struct					s_cam
{
	t_vec			pov;
	t_vec			dir;
	t_vec			ver;
	t_vec			hor;
	struct s_cam	*prev;
	struct s_cam	*next;
	float			fov;
};
typedef struct s_cam	t_cam;

//Light spot data structure
struct					s_lig
{
	t_vec	pos;
	float	rat;
	t_rgb	col;
};
typedef struct s_lig	t_lig;

//Sphere data structure
struct					s_sph
{
	float	dia;
	t_vec	pos;
	t_rgb	col;
};
typedef struct s_sph	t_sph;

//Plane data structre
struct					s_pla
{
	t_vec	pos;
	t_vec	dir;
	t_rgb	col;
};
typedef struct s_pla	t_pla;

//Cylinder data structure
struct					s_cyl
{
	t_vec	pos;
	t_vec	dir;
	float	dia;
	float	hgt;
	t_rgb	col;
};
typedef struct s_cyl	t_cyl;

//Straight line data structure
struct					s_lin
{
	t_vec	pos;
	t_vec	dir;
};
typedef struct s_lin	t_lin;

//Any object container
struct					s_obj
{
	char			type;
	void			*obj;
	struct s_obj	*next;
};
typedef struct s_obj	t_obj;

//Scene data structure
struct					s_scn
{
	t_cam	*cam;
	t_amb	amb;
	t_obj	*lig;
	t_obj	*obj;
};
typedef struct s_scn	t_scn;

//Image data structure
struct					s_img
{
	void	*iid;
	char	*iad;
	int		bpp;
	int		opl;
	int		end;
};
typedef struct s_img	t_img;

//MLX miniRT session structure
struct					s_win
{
	void			*cid;
	void			*wid;
	t_img			scr;
	uint32_t		w;
	uint32_t		h;
	t_scn			scn;
};
typedef struct s_win	t_win;

#endif
