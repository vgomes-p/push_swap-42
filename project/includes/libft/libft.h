/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:50 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:50 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_putchar(char c);
int		ft_putstr(char *st);
int		ft_putstr_nl(char *st);
int		ft_puthexdec(char *hex, unsigned long int nbr);
char	*ft_uitoa(unsigned int nb);
int		ft_intlen(long int nb);
int		ft_strcmp(const char *st1, const char *st2);

int		ft_printf(const char *fstr, ...);
int		validate_string(const char *fstr);
int		handle_char(va_list *args);
int		handle_string(va_list *args);
int		handle_ptr(va_list *args);
int		handle_lhex(va_list *args);
int		handle_uhex(va_list *args);
int		handle_int(va_list *args);
int		handle_unsigned_int(va_list *args);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *st);
void	*ft_memset(void *buff, int c, size_t n);
void	ft_bzero(void *st, size_t nb);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t destsz);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *st, int c);
char	*ft_strrchr(const char *st, int c);
int		ft_strncmp(const char *st1, const char *st2, size_t n);
void	*ft_memchr(const void *st, int c, size_t n);
int		ft_memcmp(const void *st1, const void *st2, size_t n);
char	*ft_strnstr(const char *st1, const char *st2, size_t n);
int		ft_atoi(const char *st);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *st);

char	*ft_substr(char const *st, unsigned int start, size_t len);
char	*ft_strjoin(char const *st1, char const *st2);
char	*ft_strtrim(char const *st, char const *set);
char	**ft_split(char const *str, char ch);
char	*ft_itoa(int nb);
char	*ft_strmapi(char const *st, char (*ftn)(unsigned int, char));
void	ft_striteri(char *st, void (*ftn)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *st, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif