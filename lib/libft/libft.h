/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:39:11 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/31 11:31:57 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define B_SIZE BUFFER_SIZE

struct					s_list
{
	void				*content;
	struct s_list		*next;
};
typedef struct s_list	t_list;

struct					s_opt
{
	char	hyp;
	char	zer;
	char	per;
	char	pou;
	char	spa;
	char	plu;
	size_t	wid;
	size_t	pre;
};
typedef struct s_opt	t_opt;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *str, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
size_t	ft_putchar_l(char c, int fd);
size_t	ft_putchar_lo(t_opt opt, char c, int fd);
size_t	ft_putnchar_l(size_t n, char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_putstr_l(char *s, int fd);
size_t	ft_putstr_lo(t_opt opt, char *s, int fd, size_t ret);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_putnbr_l(int n, int fd, size_t ret);
size_t	ft_putnbr_lo(t_opt opt, int n, int fd, size_t ret);
size_t	ft_putnbru_l(unsigned int n, int fd, size_t ret);
size_t	ft_putnbru_lo(t_opt opt, unsigned int n, int fd, size_t ret);
size_t	ft_putnbrh_l(char up, unsigned int n, int fd, size_t ret);
size_t	ft_putnbrx_lo(t_opt opt, unsigned int n, int fd, size_t ret);
size_t	ft_putnbrux_lo(t_opt opt, unsigned int n, int fd, size_t ret);
size_t	ft_putnbrad_l(unsigned long long n, int fd, size_t ret);
size_t	ft_putnbrad_lo(t_opt opt, unsigned long long n, int fd, size_t ret);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *str, ...);
size_t	ft_maxof(size_t a, size_t b);
size_t	ft_minof(size_t a, size_t b);
char	*get_next_line(int fd);
int		is_eol_in(char *str);
void	*return_and_free(void *ret, void *ptr);

#endif
