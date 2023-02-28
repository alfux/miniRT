/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:11:47 by alfux             #+#    #+#             */
/*   Updated: 2023/02/23 18:38:27 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_vec	*ft_newvec_tab(t_list *lst)
{
	t_vec	*new;
	size_t	i;

	new = ft_calloc(ft_lstsize(lst) + 1, sizeof (t_vec));
	if (!new)
		return (new);
	i = 0;
	while (lst)
	{
		*(new + i++) = *(t_vec *)lst->content;
		lst = lst->next;
	}
	*(new + i) = ft_setvec(NAN, NAN, NAN);
	return (new);
}

static t_idx	*ft_newidx_tab(t_list *lst)
{
	t_idx	*new;
	size_t	i;

	new = ft_calloc(ft_lstsize(lst) + 1, sizeof (t_idx));
	if (!new)
		return (new);
	i = 0;
	while (lst)
	{
		*(new + i++) = *(t_idx *)lst->content;
		lst = lst->next;
	}
	(new + i)->a.v = (size_t)-1;
	(new + i)->a.t = (size_t)-1;
	(new + i)->a.n = (size_t)-1;
	(new + i)->b.v = (size_t)-1;
	(new + i)->b.t = (size_t)-1;
	(new + i)->b.n = (size_t)-1;
	(new + i)->c.v = (size_t)-1;
	(new + i)->c.t = (size_t)-1;
	(new + i)->c.n = (size_t)-1;
	return (new);
}

static t_imp	*ft_new_struct(t_dat *dat)
{
	t_imp	*new;

	new = ft_calloc(1, sizeof (t_imp));
	if (!new)
		return ((t_imp *)0);
	new->vtx = ft_newvec_tab(dat->v);
	if (!new->vtx && !ft_free(new))
		return ((t_imp *)0);
	new->txt = ft_newvec_tab(dat->vt);
	if (!new->txt && !ft_free(new->vtx) && !ft_free(new))
		return ((t_imp *)0);
	new->nml = ft_newvec_tab(dat->vn);
	if (!new->nml && !ft_free(new->txt) && !ft_free(new->vtx) && !ft_free(new))
		return ((t_imp *)0);
	new->idx = ft_newidx_tab(dat->f);
	if (!new->idx && !ft_free(new->nml) && !ft_free(new->txt))
		return ((t_imp *)(size_t)(ft_free(new + ft_free(new->vtx))));
	return (new);
}

t_imp	*ft_getimp(/*char const *file*/int fd)
{
//	int		fd;
	t_dat	dat;
	char	*line;
	t_imp	*new;

//	fd = open(file, O_RDONLY);
//	if (fd == -1)
//		return ((t_imp *)0);
	ft_bzero(&dat, sizeof (t_dat));
	line = get_next_line(fd);
	while (line)
	{
		if (ft_addelm(line, &dat))
			return ((t_imp *)(size_t)(ft_clrdat(&dat) + ft_free(line)));
		(void)ft_free(line);
		line = get_next_line(fd);
	}
//	if (close(fd))
		return ((t_imp *)(size_t)ft_clrdat(&dat));
	new = ft_new_struct(&dat);
	(void)ft_clrdat(&dat);
	return (new);
}
