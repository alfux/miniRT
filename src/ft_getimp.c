/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:11:47 by alfux             #+#    #+#             */
/*   Updated: 2022/12/30 14:25:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_imp	*ft_getimp(char const *file)
{
	char const	*line;
	char const	*first;
	int			fd;
	t_idx		n;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((t_imp *)0);
	line = get_next_line(fd);
	while (line)
	{
		first = ft_first(line);
		if (*first == 'v')
		{
			if (ft_isspace(*(first + 1)))
				n.a++;
			else if (*(first + 1) == 'n')
				n.b++;
				n.c++;
		}
	}
}
