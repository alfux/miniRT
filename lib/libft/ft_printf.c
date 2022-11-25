/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:52:59 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/16 17:55:02 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	ft_isopt(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static t_opt	ft_init_opt(void )
{
	t_opt	opt;

	opt.hyp = 0;
	opt.zer = 0;
	opt.per = 0;
	opt.pou = 0;
	opt.spa = 0;
	opt.plu = 0;
	opt.wid = 0;
	opt.pre = 0;
	return (opt);
}

static t_opt	ft_get_opt(const char *str, size_t *i, t_opt options)
{
	while (ft_isopt(*(str + *i)))
	{
		if (*(str + *i) == '-')
			options.hyp = 1;
		else if (*(str + *i) == '0')
			options.zer = 1;
		else if (*(str + *i) == '#')
			options.pou = 1;
		else if (*(str + *i) == ' ')
			options.spa = 1;
		else
			options.plu = 1;
		(*i)++;
	}
	options.wid = ft_atoi(str + *i);
	while (ft_isdigit(*(str + *i)))
		(*i)++;
	if (*(str + *i) == '.')
	{
		options.per = 1;
		options.pre = ft_atoi(str + ++(*i));
	}
	while (ft_isdigit(*(str + *i)))
		(*i)++;
	return (options);
}

static size_t	ft_evaluate(const char *str, size_t *i, va_list *argl)
{
	size_t	l;
	t_opt	op;

	l = 0;
	op = ft_init_opt();
	op = ft_get_opt(str, i, op);
	if (*(str + *i) == 'c')
		l = ft_putchar_lo(op, (char)va_arg(*argl, int), 1);
	else if (*(str + *i) == 's')
		l = ft_putstr_lo(op, (char *)va_arg(*argl, char *), 1, 0);
	else if (*(str + *i) == 'p')
		l = ft_putnbrad_lo(op, (long long)va_arg(*argl, void *), 1, 0);
	else if (*(str + *i) == 'i' || *(str + *i) == 'd')
		l = ft_putnbr_lo(op, (int)va_arg(*argl, int), 1, 0);
	else if (*(str + *i) == 'u')
		l = ft_putnbru_lo(op, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (*(str + *i) == 'x')
		l = ft_putnbrx_lo(op, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (*(str + *i) == 'X')
		l = ft_putnbrux_lo(op, (unsigned int)va_arg(*argl, unsigned int), 1, 0);
	else if (*(str + *i) == '%')
		l = ft_putchar_lo(op, *(str + *i), 1);
	else
		l = ft_putstr_l("{Flag does not exist}", 1);
	return (l);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	argl;

	i = 0;
	len = 0;
	va_start(argl, str);
	while (*(str + i))
	{
		if (*(str + i++) == '%')
		{
			len += ft_evaluate(str, &i, &argl);
			i++;
		}
		else
		{
			ft_putchar_fd(*(str + i - 1), 1);
			len++;
		}
	}
	va_end(argl);
	return (len);
}
