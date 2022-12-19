/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:51:27 by efunes            #+#    #+#             */
/*   Updated: 2022/12/19 20:21:22 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_ini_t_win(t_win *win)
{
	win->cid = NULL;
	win->wid = NULL;
	win->scr.iid = NULL;
	win->scr.iad = NULL;
	win->scr.bpp = 0;
	win->scr.opl = 0;
	win->scr.end = 0;
	win->w = 0;
	win->h = 0;
	win->scn.cam = NULL;
	win->scn.amb.rat = 0;
	win->scn.amb.col.r = 0;
	win->scn.amb.col.g = 0;
	win->scn.amb.col.b = 0;
	win->scn.lig = NULL;
	win->scn.obj = NULL;
}

int	ft_new_elem(t_win *win, char *str)
{
	int	err;

	err = /* value */; // error 'Bad objet's define'
	if (*str == 'A')
	// A = lumiere ambiante
	else if (*str == 'C')
	// C = camera
	else if (*str == 'L')
	// L = lumiere
	else if (*str == 'c' && *(str + 1) && *(str + 1) == 'o')
	// co = cone
	else if (*str == 'c' && *(str + 1) && *(str + 1) == 'y')
	// cy = cylindre
	else if (*str == 'h' && *(str + 1) && *(str + 1) == 'y')
	// hy = Hyperboloïde
	else if (*str == 'p' && *(str + 1) && *(str + 1) == 'a')
	// pa = Paraboloïde
	else if (*str == 'p' && *(str + 1) && *(str + 1) == 'l')
	// pl = plan
	else if (*str == 's' && *(str + 1) && *(str + 1) == 'p')
	// sp = sphere
}

int	ft_valid_extension_name(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 3)
		return (1);
	if (str[i] == 't' && str[i - 1] == 'r' && str[i - 2] == '.')
		return (0);
	return (1);
}

/* Si vous rencontrez un quelconque problème de configuration dans le fichier,
votre programme doit se fermer correctement et renvoyer "Error\n" suivi
d’un message explicite de votre choix. */
int	ft_error_manager(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (!err && errno)
		ft_putstr_fd(strerror(errno), 2);
	else if (err == 1)
		ft_putstr_fd("Invalid extension format. MiniRT works only with `.rt' extension files\n", 2)
	else if (err == /* value a definir*/)
		ft_putstr_fd("No camera found. The execution need one camera with format `C\t\t-50.0,0,20\t\t0,0,1\t\t70' to turn on.\nFirst block C is imposed for camera.\nSecond block with x, y and z coordinates, separated by comas.\nThird block whith the camera orientation' vector on the axes x, y and z\nFourth block with horizontal vision hamp in degrees in the range [0,180]\n", 2);

}
int	ft_pars(t_win *win, char *arg)
{
	int		fd;
	int		err;
	char	*line;
	size_t	i;

	ft_ini_t_win(win);
	if (ft_valid_extension_name(arg))
		return (ft_error_manager(1));
	fd = open(arg, O_RDONLY);
	if (fd < 2)
		return (ft_error_manager(0)); // Bad file descriptor
	err = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i])
			err = ft_new_elem(win, line + i);
		if (err)
			return (ft_error_manager(err)); // free la memoire utilise // close fd
		free(line);
		line = get_next_line(fd);
	}
	if (!win->scn.cam)
		return (ft_error_manager(/* value a definir */)); // No cam found // free memoire // close fd
}
