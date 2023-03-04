/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:45:35 by efunes            #+#    #+#             */
/*   Updated: 2023/03/04 17:18:29 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static size_t	ft_valid_obj_extension(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	if (i > 4 && str[i - 4] == '.' && str[i - 3] == 'o'
		&& str[i - 2] == 'b' && str[i - 1] == 'j')
		return (i);
	return (0);
}

static int	ft_obj_fd(char **str)
{
	size_t	i;
	char	*name;
	int		fd;

	while (ft_isspace(**str))
		(*str)++;
	i = ft_valid_obj_extension(*str);
	if (!i)
		return (0);
	name = ft_substr(*str, 0, i);
	if (!name)
		return (-1);
	fd = open(name, O_RDONLY);
	free(name);
	return (fd);
}

static int	ft_newimp2(t_win *window, t_imp *imp, char *str)
{
	if (ft_rgb(&(imp->col), &str))
		return (5);
	if (*str)
		return (ft_bonus_param(window, &(imp->bns), str));
	return (0);
}

int	ft_newimp(t_win *window, t_obj **obj, char *str)
{
	t_obj	*new;
	int		fd;
	
	fd = ft_obj_fd(&str);
	if (!fd)
		return (23);
	if (fd < 0)
		return (100);
	new = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!new)
		return (6);
	new->type = 'I';
	new->next = NULL;
	new->obj = ft_getimp(fd);
	close(fd);
	if (!new->obj)
		return (24);
	ft_objadd(obj, new);
	while (*str && !ft_isspace(*str))
		str++;
	if (ft_coord(&((t_imp *)(new->obj))->pos, &str))
		return (4);
	if (ft_orthonormal_basis(&((t_imp *)(new->obj))->bas, &str))
		return (20);
	return (ft_newimp2(window, (t_imp *)(new->obj), str));
}
