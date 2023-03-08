/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:51:27 by efunes            #+#    #+#             */
/*   Updated: 2023/03/08 15:53:09 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_new_elem(t_win *win, t_scn *scn, char *str)
{
	if (*str == 'A' && str[1] && ft_isspace(str[1]))
		return (ft_pars_amb(&(scn->amb), str + 1));
	else if (*str == 'C' && str[1] && ft_isspace(str[1]))
		return (ft_pars_cam(&(scn->cam), str + 1));
	else if (*str == 'L' && str[1] && ft_isspace(str[1]))
		return (ft_pars_light(&(scn->lig), str + 1));
	else if (*str && str[1] && str[2] && ft_isspace(str[2]))
	{
		if ((*str == 'c' && str[1] && str[1] == 'o')
			|| (*str == 'e' && str[1] && str[1] == 'l')
			|| (*str == 'h' && str[1] && str[1] == 'y'))
			return (ft_pars_ehc(win, &(scn->obj), str + 2, *str));
		else if (*str == 'c' && str[1] && str[1] == 'y')
			return (ft_pars_cyl(win, &(scn->obj), str + 2));
		else if (*str == 'p' && str[1] && str[1] == 'a')
			return (ft_pars_pbol(win, &(scn->obj), str + 2));
		else if (*str == 'p' && str[1] && str[1] == 'l')
			return (ft_pars_pla(win, &(scn->obj), str + 2));
		else if (*str == 's' && str[1] && str[1] == 'p')
			return (ft_pars_sph(win, &(scn->obj), str + 2));
		else if (*str == 'o' && str[1] && str[1] == 'b')
			return (ft_newimp(win, &(scn->obj), str + 2));
	}
	return (2);
}

static int	ft_valid_extension_name(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 3)
		return (1);
	if (str[i] == 't' && str[i - 1] == 'r' && str[i - 2] == '.')
		return (0);
	return (1);
}

int	ft_line_pars(t_win *win, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		return (ft_new_elem(win, &win->scn, line + i));
	return (0);
}

int	ft_pars(t_win *win, char *arg)
{
	int		fd;
	int		err;
	char	*line;

	if (ft_valid_extension_name(arg))
		return (ft_error_manager(win, 1, 0));
	fd = open(arg, O_RDONLY);
	if (fd < 2)
		return (ft_error_manager(win, 100, 0));
	line = get_next_line(fd);
	while (line)
	{
		err = ft_line_pars(win, line);
		free(line);
		if (err)
			return (ft_error_manager(win, err, fd));
		line = get_next_line(fd);
	}
	if (!win->scn.cam)
		return (ft_error_manager(win, 3, fd));
	else if (win->scn.amb.rat == -1)
		return (ft_error_manager(win, 10, fd));
	close (fd);
	win->hlp = 0;
	return (0);
}
