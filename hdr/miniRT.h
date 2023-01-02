/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2023/01/01 18:36:34 by alfux            ###   ########.fr       */
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
t_win		ft_tobase_cam(t_win win);//Deprecated atm
t_vec		ft_setvec(double x, double y, double z);
t_rgb		ft_setrgb(unsigned char r, unsigned char g, unsigned char b);
t_amb		ft_setamb(double rat, t_rgb col);
int			ft_pars_amb(t_amb *amb, char *str);
int			ft_pars_cam(t_cam **cam, char *str);
t_lin		ft_setlin(t_vec pos, t_vec dir);
t_3x3		ft_set3x3(t_vec lft, t_vec mid, t_vec rgt);
t_2x3		ft_set2x3(t_vec top, t_vec bot);

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

//Math tools
double		ft_scalar(t_vec u, t_vec v);
double		ft_distce(t_vec a, t_vec b);
double		ft_norm(t_vec u);
double		ft_det3x3(t_3x3 m);
t_3x3		ft_invmat(t_3x3 m);
t_vec		ft_nrmlze(t_vec v);
t_vec		ft_multlv(double l, t_vec v);
t_vec		ft_multmv(t_3x3 m, t_vec v);
t_vec		ft_sum_uv(t_vec u, t_vec v);
t_vec		ft_dif_uv(t_vec u, t_vec v);
t_vec		ft_provec(t_vec u, t_vec v);
t_vec		ft_polyd2(t_vec coef);
t_2x3		ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj);
t_2x3		ft_syssph(t_vec const *dir, t_vec const *pov, t_sph const *sph);
t_2x3		ft_syspla(t_vec const *dir, t_vec const *pov, t_pla const *pla);
t_2x3		ft_syscyl(t_vec const *dir, t_vec const *pov, t_cyl const *cyl);
t_list		*ft_sysimp(t_vec const *dir, t_vec const *pov, t_imp const *imp);
int			ft_is_sol(t_2x3 const *itr);
int			ft_is_val(t_vec const *v);

//Other tools
int			ft_free(void *ptr);
int			ft_cleardat(t_dat *dat);
int			ft_delimp(t_imp *imp);
uint32_t	ft_rgbtoi(t_rgb rgb);
void		ft_print_scene(t_scn scn);
void		ft_print_vect(t_vec v);
void		ft_print_inter_sph(t_vec ray, t_sph *sph, t_2x3 inter);
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
void		ft_movobj(int mid, t_obj *cur);

//Rendering
void		ft_render(t_win const *win);
t_vec		ft_getdir(t_win const *win, uint32_t i, uint32_t j);
t_vec		ft_closer_to_pov(t_2x3 const *cmp, t_vec const *pov);
int			ft_face_cam(t_2x3 *intr, t_vec const *pov, t_vec const *ray);
t_rgb		ft_objrgb(t_obj const *obj);
int			ft_iscloser(t_vec const *vec, t_vec const *tmp, t_vec const *pov);
uint32_t	ft_raytra(t_win const *win, t_vec const *ray, t_obj const *obj);
int			ft_deadzn(t_2x3 *i, t_vec const *p, double dz);
double		ft_shdsph(t_win const *win, t_sph const *s, t_vec const *p);
double		ft_shdcyl(t_win const *win, t_cyl const *c, t_vec const *p);
double		ft_shdpla(t_win const *win, t_pla const *pl, t_vec const *p);
t_rgb		ft_shades(t_win const *win, t_obj const *obj, t_vec const *vec,
				t_rgb const *rgb);
int			ft_clside(t_vec const *i, t_vec const *p, t_vec const *n,
				t_vec const *l);

//Easter eggs
void		ft_eeggs(t_cam *cam);

#endif
