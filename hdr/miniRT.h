/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2023/02/09 09:09:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <sys/errno.h>
# include <mlx.h>
# include <libft.h>
# include <dataRT.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>

//Structure filling
int			ft_pars(t_win *win, char *arg);
t_win		ft_setwin(int width, int height, char *title);
void		ft_setcam(t_cam *cam);
t_vec		ft_setvec(double x, double y, double z);
t_rgb		ft_setrgb(unsigned char r, unsigned char g, unsigned char b);
t_amb		ft_setamb(double rat, t_rgb col);
int			ft_pars_amb(t_amb *amb, char *str);
int			ft_pars_cam(t_cam **cam, char *str);
t_3x3		ft_set3x3(t_vec lft, t_vec mid, t_vec rgt);

//Object allocation
t_lig		*ft_newlig(t_vec pos, double rat, t_rgb col);
int			ft_pars_light(t_obj **lig, char *str);
t_sph		*ft_newsph(double dia, t_vec pos, t_rgb col);
int			ft_pars_sph(t_obj **obj, char *str);
t_pla		*ft_newpla(t_vec pos, t_vec dir, t_rgb col);
int			ft_pars_pla(t_obj **obj, char *str);
t_cyl		*ft_newcyl(t_vec pos, t_vec dir, t_vec dh, t_rgb col);
int			ft_pars_cyl(t_obj **lig, char *str);
char		ft_datatp(char const *line);
int			ft_addelm(char const *line, t_dat *dat);
t_imp		*ft_getimp(char const *file);

//Object list manipulation
t_obj		*ft_objnew(char type, void *obj);
void		ft_objadd(t_obj **obj, t_obj *add);
void		ft_objdelone(t_obj *obj, void (*del)(void *));
void		ft_objclear(t_obj **obj, void (*del)(void *));
void		ft_camclear(t_cam **cam, void (*del)(void *));
int			ft_lstadd_new(t_list **lst, void *content);
int			ft_lstclear_return(t_list **lst, int ret);
void		ft_lstrem(t_list **lst, t_list *rem);

//Math tools
double		ft_scalar(t_vec u, t_vec v);
double		ft_distce(t_vec a, t_vec b);
double		ft_norm(t_vec u);
double		ft_det3x3(t_3x3 m);
t_3x3		ft_invmat(t_3x3 m);
t_vec		ft_nrmlze(t_vec v);
t_vec		ft_multlv(double l, t_vec v);
t_vec		ft_multmv(t_3x3 m, t_vec v);
t_3x3		ft_multmm(t_3x3 a, t_3x3 b);
t_3x3		ft_rotnml(t_3x3 const *bas, t_vec const *v, double phi);
t_vec		ft_sum_uv(t_vec u, t_vec v);
t_vec		ft_dif_uv(t_vec u, t_vec v);
t_vec		ft_provec(t_vec u, t_vec v);
t_vec		ft_polyd2(t_vec coef);
t_list		*ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj);
t_list		*ft_sysimp(t_vec const *dir, t_vec const *pov, t_imp const *imp);
t_list		*ft_syssph(t_vec const *dir, t_vec const *pov, t_sph const *sph);
t_list		*ft_syspla(t_vec const *dir, t_vec const *pov, t_pla const *pla);
t_list		*ft_syscyl(t_vec const *dir, t_vec const *pov, t_cyl const *cyl);
double		ft_cylhgt(t_vec const *p, t_cyl const *c);
int			ft_is_val(t_vec const *v);
t_rgb		ft_addrgb(t_rgb c1, t_rgb c2);
t_rgb		ft_ambrgb(t_rgb const *rgb, t_amb const *amb);
t_rgb		ft_ligrgb(t_itr const *vtx, t_vec const *ray, t_lig const *lig,
				double i);

//Other tools
int			ft_free(void *ptr);
int			ft_clrdat(t_dat *dat);
int			ft_delimp(t_imp *imp);
uint32_t	ft_rgbtoi(t_rgb rgb);
void		ft_print_scene(t_scn scn);
void		ft_print_vect(t_vec v);
int			ft_pars_double(double *shr, char **str);
int			ft_rgb(t_rgb *rgb, char **str);
int			ft_coord(t_vec *vec, char **str);
int			ft_skipdigit(char const **str);
int			ft_skipspace(char const **str);
int			ft_skipnodigit(char const **str);

//Memory free exits
int			ft_exit_success(t_win *win);
int			ft_exit_failure(t_win *win, char const *msg);
int			ft_exit(t_win *win, int status);

//Key hooks
int			ft_keyhook(int kid, t_win *win);
int			ft_mousehook(int mid, int x, int y, t_win *win);
void		ft_movobj(int mid, t_obj *cur, t_cam *cam);

//Rendering
void		ft_render(t_win const *win);
t_vec		ft_getdir(t_win const *win, uint32_t i, uint32_t j);
uint32_t	ft_raytra(t_win const *win, t_vec const *ray, t_obj const *obj);
int			ft_deadzn(t_vec const *vec, t_vec const *ctr, double rad);
t_rgb		ft_shades(t_win const *win, t_vec const *ray, t_list *itr);
t_rgb		ft_sphrgb(t_vec const *vtx, t_sph const *sph);
t_rgb		ft_plargb(t_vec const *vtx, t_pla const *sph);
t_rgb		ft_cylrgb(t_vec const *vtx, t_cyl const *cyl);
t_vec		ft_sphbmp(t_vec const *vtx, t_sph const *sph);
t_vec		ft_bmpmap(double x, double y);

//Easter eggs
void		ft_eeggs(t_cam *cam);

#endif
