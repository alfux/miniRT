/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:33:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/31 11:34:08 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_cpy(char *dst, char *buf, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && dst && buf)
	{
		*(dst + i) = *(buf + i);
		i++;
	}
}

static char	*rec_gnl(int fd, char *buf, size_t len)
{
	ssize_t	n_read;
	size_t	n_buf;
	char	*str;
	char	*r_buf;

	r_buf = ft_calloc(sizeof (char), B_SIZE);
	n_read = read(fd, r_buf, B_SIZE);
	if ((!n_read && !len) || n_read == -1)
		return (return_and_free((void *)0, r_buf));
	n_buf = is_eol_in(r_buf);
	if (!n_buf && n_read)
	{
		str = rec_gnl(fd, buf, len + n_read);
		ft_cpy(str + len, r_buf, n_read);
		return ((char *)return_and_free(str, r_buf));
	}
	len += n_buf;
	str = ft_calloc(sizeof (char), len + 1);
	if (!str)
		return (return_and_free((void *)0, r_buf));
	*(str + len) = '\0';
	ft_cpy(str + len - n_buf, r_buf, n_buf);
	ft_cpy(buf, r_buf, B_SIZE);
	return ((char *)return_and_free(str, r_buf));
}

static char	*terminate_and_clean(char *r_buf, char *buf, size_t st, size_t re)
{
	char	*swap;

	swap = ft_calloc(sizeof (char), B_SIZE);
	ft_cpy(swap, buf + st + re, B_SIZE - st - re);
	ft_cpy(buf, swap, B_SIZE);
	*(r_buf + re + 1) = '\0';
	*(r_buf + re) = '\n';
	return (return_and_free(r_buf, swap));
}

static char	*process_buf(int fd, char *buf)
{
	size_t		st;
	size_t		re;
	char		*r_buf;
	char		*str;

	st = 0;
	re = 0;
	r_buf = (void *)0;
	while (*(buf + st) != '\n')
		st++;
	if (st + 1 < B_SIZE)
	{
		st++;
		while (st + re < B_SIZE && *(buf + st + re) && *(buf + st + re) != '\n')
			re++;
		r_buf = ft_calloc(sizeof (char), re + 2);
		if (!r_buf)
			return ((void *)0);
		ft_cpy(r_buf, buf + st, re);
		if (st + re < B_SIZE && *(buf + st + re) == '\n')
			return (terminate_and_clean(r_buf, buf, st, re));
	}
	str = rec_gnl(fd, buf, re);
	ft_cpy(str, r_buf, re);
	return (return_and_free(str, r_buf));
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][B_SIZE];

	if (fd < 0 || fd >= OPEN_MAX || B_SIZE < 1)
		return ((void *)0);
	if (!**(buf + fd) || B_SIZE == 1)
		return (rec_gnl(fd, *(buf + fd), 0));
	return (process_buf(fd, *(buf + fd)));
}
