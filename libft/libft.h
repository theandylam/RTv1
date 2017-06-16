/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:04:30 by alam              #+#    #+#             */
/*   Updated: 2017/04/28 16:55:14 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# define HEX_DIGITS "0123456789ABCDEF"

# define GNL_BUFFER 256

# define UDATA 0b10000000
# define UDATA_MASK 0b00111111
# define UMASK_1 0b01111111
# define UHEAD_2 0b11000000
# define UMASK_2 0b00011111
# define UHEAD_3 0b11100000
# define UMASK_3 0b00001111
# define UHEAD_4 0b11110000
# define UMASK_4 0b00000111

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_file
{
	int		fc;
	char	leftover[GNL_BUFFER];
}				t_file;

int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
unsigned int	ft_strlcat(char *dst, const char *src, size_t size);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int input);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int input);
char			*ft_strstr(const char *big, const char *little);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_iswhtspc(char c);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddback(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstprintstr(t_list **lst);

int				ft_abs(int n);
int				ft_sqrt(int nb);
void			ft_print_binary(unsigned char octet);
void			ft_lstfree(void *content, size_t size);
char			*ft_itoa_base(long long value, int base);
void			ft_putlong(long n);
void			ft_putlong_u(unsigned long n);
void			ft_strupper(char *s);
void			ft_strlower(char *s);
int				ft_putwchar(wchar_t c);
int				ft_putwstr(wchar_t const *s);
int				ft_putnstr(char const *s, int n);
int				ft_putnwstr(wchar_t const *s, int n);
size_t			ft_wstrlen(const wchar_t *s);
size_t			ft_wstrsize(const wchar_t *s);
char			*ft_itoa_base_u(unsigned long long value, int base);
size_t			ft_wstrnsize(const wchar_t *s, size_t max);

int				get_next_line(const int fd, char **line);

void			ft_freesplit(char **str);

int				ft_printf(const char *format, ...);

#endif
