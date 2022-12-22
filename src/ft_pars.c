/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:51:27 by efunes            #+#    #+#             */
/*   Updated: 2022/12/22 20:31:59 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/* Si vous rencontrez un quelconque problème de configuration dans le fichier,
votre programme doit se fermer correctement et renvoyer "Error\n" suivi
d’un message explicite de votre choix. */
int	ft_error_manager(int err, char *line)
{
	ft_putstr_fd("Error\n", 2);
	if (line)
		free(line);
	if (!err && errno)
		ft_putstr_fd(strerror(errno), 2);
	else if (err == 1)
		ft_putstr_fd("Invalid extension format. MiniRT works only with `.rt' extension files\n", 2);
	else if (err == 2)
		ft_putstr_fd("Invalid object's definition\n", 2);
	else if (err == 3)
		ft_putstr_fd("No camera found. The execution need one camera with format `C\t\t-50.0,0,20\t\t0,0,1\t\t70' to turn on.\nFirst block C is imposed for camera.\nSecond block with x, y and z coordinates, separated by comas.\nThird block whith the camera orientation' vector on the axes x, y and z\nFourth block with horizontal vision hamp in degrees in the range [0,180]\n", 2);
	else if (err == 4)
		ft_putstr_fd("Invalid object's coordonates or orientation\n", 2);
	else if (err == 5)
		ft_putstr_fd("Invalid object's rgb definition\n", 2);
	else if (err == 6)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (err == 7)
		ft_putstr_fd("Invalid light ratio\n", 2);
	else if (err == 8)
		ft_putstr_fd("Invalid Camera FOV. FOV must be an integer between 0 and 180\n", 2);
	else if (err == 9)
		ft_putchar_fd("invalid Camera argument\n", 2);
	else if (err == 10)
		ft_putchar_fd("invalid Ambiant Light argument\n", 2);
	return (1);
}

int	ft_new_elem(t_scn *scn, char *str)
{
	int	err;

	err = /* value */; // error 'Bad objet's define'
	if (*str == 'A' && str[1] && ft_isspace(str[1]))
		return (ft_pars_amb(&(scn->amb), &str)); // A = lumiere ambiante
	else if (*str == 'C' && str[1] && ft_isspace(str[1]))
		return (ft_pars_cam(&(scn->cam), &str));// C = camera
	else if (*str == 'L' && str[1] && ft_isspace(str[1]))
		return ();// L = lumiere
	else if (*str && str[1] && str[2] && ft_isspace(str[2]))
	{
		if (*str == 'c' && str[1] && str[1] == 'o')
			return ();// co = cone
		else if (*str == 'c' && str[1] && str[1] == 'y')
			return ();// cy = cylindre
		else if (*str == 'h' && str[1] && str[1] == 'y')
			return ();// hy = Hyperboloïde
		else if (*str == 'p' && str[1] && str[1] == 'a')
			return ();// pa = Paraboloïde
		else if (*str == 'p' && str[1] && str[1] == 'l')
			return ();// pl = plan
		else if (*str == 's' && str[1] && str[1] == 'p')
			return ();// sp = sphere
	}
	return (1);
}

int	ft_valid_extension_name(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 3)
		return (1);
	if (str[i] == 't' && str[i - 1] == 'r' && str[i - 2] == '.')
		return (0);
	return (2);
}

int	ft_pars(t_win *win, char *arg)
{
	int		fd;
	int		err;
	char	*line;
	size_t	i;

	if (ft_valid_extension_name(arg))
		return (ft_error_manager(1, NULL));
	fd = open(arg, O_RDONLY);
	if (fd < 2)
		return (ft_error_manager(0, NULL)); // Bad file descriptor
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		err = 0;
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i])
			err = ft_new_elem(win, line + i);
		if (err)
			return (ft_error_manager(err, line)); // free la memoire utilise // close fd
		free(line);
		line = get_next_line(fd);
	}
	if (!win->scn.cam)
		return (ft_error_manager(3)); // No cam found // free memoire // close fd
	return (0);
}