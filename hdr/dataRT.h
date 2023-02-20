/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2023/02/20 09:31:30 by alfux            ###   ########.fr       */
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
# define K_A 12
# define K_E 14
# define K_L 37
# define K_O 31
# define K_F 3
# define K_G 5
# define K_H 4
# define K_J 38
# define K_C 8
# define K_V 9
# define K_B 11
# define K_N 45
# define K_I 34
# define K_K 40
# define K_SPACE 49
# define K_COMA 43
# define M_LEFT 1
# define M_RIGHT 2

//Screen resolution
# define RESOLUTION 1280
# define LOW_R 80

//Constants
# define EPSILON 0.0000001
# define DEADZONE 0.02
# define GAMMA 2

//Vetcor data structure
struct					s_vec
{
	double	x;
	double	y;
	double	z;
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

//Color data structure
struct					s_rgb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};
typedef struct s_rgb	t_rgb;

//Specular parameters
struct					s_spc
{
	double	siz;
	double	har;
};
typedef struct s_spc	t_spc;

//Intersection data structure
struct					s_itr
{
	t_vec	vtx;
	t_vec	nml;
	t_vec	bmp;
	t_rgb	col;
	t_spc	spc;
};
typedef struct s_itr	t_itr;

//Ambiant light data structure
struct					s_amb
{
	double	rat;
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
	double			fov;
};
typedef struct s_cam	t_cam;

//Light spot data structure
struct					s_lig
{
	t_vec	pos;
	double	rat;
	t_rgb	col;
};
typedef struct s_lig	t_lig;

//Image data structure
struct					s_img
{
	void	*iid;
	char	*iad;
	int		bpp;
	int		opl;
	int		end;
	int		w;
	int		h;
};
typedef struct s_img	t_img;

//Sphere data structure
struct					s_sph
{
	double	dia;
	t_vec	pos;
	t_rgb	col;
	t_spc	spc;
	t_3x3	bas;
	t_rgb	co2;
	t_img	bmp;
};
typedef struct s_sph	t_sph;

//Ellipse data structure
struct					s_ell
{
	double	dia;
	double	hgt;
	t_vec	dir;
	t_vec	pos;
	t_vec	rat;
	t_rgb	col;
	t_spc	spc;
	t_3x3	bas;
	t_rgb	co2;
	t_img	bmp;
};
typedef struct s_ell	t_ell;

//parabol
struct					s_pbol
{
	double	dia;
	t_vec	pos;
	t_vec	rat;
	t_vec	dir;
	t_rgb	col;
};
typedef struct s_pbol	t_pbol;

//hyperbol
struct					s_hbol
{
	double	dia;
	t_vec	pos;
	t_vec	rat;
	t_vec	dir;
	t_rgb	col;
};
typedef struct s_hbol	t_hbol;

//hyperbol
struct					s_cone
{
	double	dia;
	double	hgt;
	t_vec	pos;
	t_vec	dir;
	t_rgb	col;
};
typedef struct s_cone	t_co;

//Plane data structre
struct					s_pla
{
	t_vec	pos;
	t_vec	dir;
	t_rgb	col;
	t_spc	spc;
	t_3x3	bas;
	t_rgb	co2;
	t_img	bmp;
};
typedef struct s_pla	t_pla;

//Cylinder data structure
struct					s_cyl
{
	t_vec	pos;
	t_vec	dir;
	double	dia;
	double	hgt;
	t_rgb	col;
	t_spc	spc;
	t_3x3	bas;
	t_rgb	co2;
	t_img	bmp;
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

//MLX miniRT session structure
struct					s_win
{
	void			*cid;
	void			*wid;
	t_img			scr;
	uint32_t		w;
	uint32_t		h;
	t_scn			scn;
	char			mod;
	t_obj			*cur;
};
typedef struct s_win	t_win;

//---------OBJ files data extraction structures---------------------------------
//Data extraction lists
struct					s_dat
{
	t_list	*v;
	t_list	*vt;
	t_list	*vn;
	t_list	*f;
};
typedef struct s_dat	t_dat;

//Vertex Texture Normal triplet
struct					s_vtn
{
	size_t	v;
	size_t	t;
	size_t	n;
};
typedef struct s_vtn	t_vtn;

//Index data structure
struct					s_idx
{
	t_vtn	a;
	t_vtn	b;
	t_vtn	c;
};
typedef struct s_idx	t_idx;

//Polyhedrons data structure
struct					s_imp
{
	t_vec	*vtx;
	t_vec	*txt;
	t_vec	*nml;
	t_idx	*idx;
	t_rgb	col;
	t_spc	spc;
};
typedef struct s_imp	t_imp;
//------------------------------------------------------------------------------

//Easter eggs
# define EEGGS 111

#endif
