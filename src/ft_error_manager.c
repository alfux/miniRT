/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:04:11 by efunes            #+#    #+#             */
/*   Updated: 2023/03/08 16:10:53 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_em3(int err)
{
	if (err == 17)
		ft_putstr_fd("invalid color perturbation argument.\n", 2);
	else if (err == 18)
		ft_putstr_fd("invalid bumpmap argument.\n", 2);
	else if (err == 19)
		ft_putstr_fd("invalid bumpmap file.\n", 2);
	else if (err == 20)
		ft_putstr_fd("vectors of the reference basis are collinear.\n", 2);
	else if (err == 21)
		ft_putstr_fd("invalid specular-perturbation-bumpmap selector.\n", 2);
	else if (err == 22)
		ft_putstr_fd("invalid specular-perturbation-bumpmap's argument's \
		line.\n", 2);
	else if (err == 23)
		ft_putstr_fd("invalid objet `ob' extension filed.\n", 2);
	else if (err == 24)
		ft_putstr_fd("error on memory allocation or on `.obj' file.\n", 2);
	else if (err == 25)
		ft_putstr_fd("invalid objet argument.\n", 2);
}

void	ft_em2(int err)
{
	if (err == 7)
		ft_putstr_fd("Invalid light ratio.\n", 2);
	else if (err == 8)
		ft_putstr_fd("Invalid Camera FOV. FOV must be an integer between 0 and \
		180.\n", 2);
	else if (err == 9)
		ft_putstr_fd("invalid Camera argument.\n", 2);
	else if (err == 10)
		ft_putstr_fd("invalid Ambiant Light argument.\n", 2);
	else if (err == 11)
		ft_putstr_fd("invalid Light argument.\n", 2);
	else if (err == 12)
		ft_putstr_fd("invalid diameter.\n", 2);
	else if (err == 13)
		ft_putstr_fd("invalid height.\n", 2);
	else if (err == 14)
		ft_putstr_fd("invalid cylinder argument.\n", 2);
	else if (err == 15)
		ft_putstr_fd("invalid plan argument.\n", 2);
	else if (err == 15)
		ft_putstr_fd("invalid sphere argument.\n", 2);
	else if (err == 16)
		ft_putstr_fd("invalid hyperbol or parabol or ellipse ratio.\n", 2);
	ft_em3(err);
}

int	ft_error_manager(t_win *win, int err, int fd)
{
	ft_putstr_fd("Error\n", 2);
	if (fd)
		close(fd);
	if (err > 99 && errno)
		perror("");
	else if (err == 1)
		ft_putstr_fd("Invalid extension format.\n MiniRT works only with `.rt' \
		extension files.\n", 2);
	else if (err == 2)
		ft_putstr_fd("Invalid object's definition.\nValid definition are \
		<camera>`C'\t <light>`L'\t<ambiant light.`L'\t<sphere>`sp'\t<plan>`pl'\
		\t<cylinder>`cy'\t<ellipse>`el'\t<hyperbol>`hy'\t<parabol>`pa'\
		\t<cone>`co'\t<.obj filed extension>`ob'\n", 2);
	else if (err == 3)
		ft_putstr_fd("No camera found.\n The execution need one camera with \
		format `C\t<position>x,y,z\t\t<orientation vector>x,y,z\t\t<vision ham.\
		[0-180] to turn on.\n", 2);
	else if (err == 4)
		ft_putstr_fd("Invalid object's coordonates or orientation.\n", 2);
	else if (err == 5)
		ft_putstr_fd("Invalid object's rgb definition.\n", 2);
	else if (err == 6)
		ft_putstr_fd("Memory allocation failed.\n", 2);
	ft_em2(err);
	return (ft_exit(win, 1));
}
