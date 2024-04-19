/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 15:34:40 by cavan-vl      #+#    #+#                 */
/*   Updated: 2023/11/04 21:38:32 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

/*===============================CLASS================================*/

int			ft_isalpha(int c);
int			ft_isdigit(int d);
int			ft_isalnum(int a);
int			ft_isascii(int c);
int			ft_isprint(int c);

int			ft_tolower(int c);
int			ft_toupper(int c);

/*===============================STRING================================*/

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n, int base);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

char		**ft_split(char *s, char c);

int			ft_strlen(char *s);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlcat(char *dest, char *src, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strrchr(char *s, int c);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);
char		*ft_strtrim(char *s1, char *set);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		free_array(char **array);
char		**copy_array(char **array, int size);

/*===============================MEMORY================================*/

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_malloc(size_t size);

/*===============================OUTPUT================================*/

int			ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			error_msg(char *msg);

/*===============================LIST================================*/

typedef struct s_liblist
{
	void				*content;
	struct s_liblist	*next;
}	t_liblist;

void		ft_lstadd_back(t_liblist **lst, t_liblist *new);
void		ft_lstadd_front(t_liblist **lst, t_liblist *new);
void		ft_lstclear(t_liblist **lst, void (*del)(void *));
void		ft_lstdelone(t_liblist *lst, void (*del)(void *));
void		ft_lstiter(t_liblist *lst, void (*f)(void *));
t_liblist	*ft_lstlast(t_liblist *lst);
t_liblist	*ft_lstmap(t_liblist *lst, void *(*f)(void *), void (*del)(void *));
t_liblist	*ft_lstnew(void *content);
int			ft_lstsize(t_liblist *lst);

#endif