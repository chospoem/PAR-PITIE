/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:17:50 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/15 14:30:06 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			ft_isalnum(int c);//testé
int			ft_isalpha(int c);//testé
int			ft_isascii(int c);//a tester
int			ft_isdigit(int c);//testé
int			ft_isprint(int c);//flemme de tester
size_t		ft_strlen(const char *s);//testé
char		*ft_substr(char const *s, unsigned int start, size_t len);//testé
char		*ft_strjoin(char const *s1, char const *s2);//testé
char		*ft_itoa(int n);//testé
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));//testé
char		**ft_split(char const *s, char c);//testé
void		*ft_memset(void *s, int c, size_t n);//testé
void		ft_bzero(void *s, size_t n);//testé
void		*ft_memcpy(void *dest, const void *src, size_t n);//testé
void		*ft_memmove(void *dest, const void *src, size_t n);//testé
size_t		ft_strlcpy(char *dest, const char *src, size_t size);//testé
size_t		ft_strlcat(char *dst, const char *src, size_t size);//testé
int			ft_toupper(int c);//testé
int			ft_tolower(int c);//testé
char		*ft_strchr(const char *s, int c);//testé
char		*ft_strrchr(const char *s, int c);//testé
int			ft_strncmp(const char *s1, const char *s2, size_t n);//testé
void		*ft_memchr(const void *s, int c, size_t n);//testé
int			ft_memcmp(const void *s1, const void *s2, size_t n);//testé
char		*ft_strnstr(const char *big, const char *little, size_t len);//testé
long int	ft_atoi(const char *nptr);//testé
char		*ft_strdup(const char *s);//testé
void		*ft_calloc(size_t nmemb, size_t size);//testé
void		ft_putchar_fd(char c, int fd);//testé-vérifier
void		ft_putstr_fd(char *s, int fd);//testé-vérifier
void		ft_putendl_fd(char *s, int fd);//testé-vérifier
void		ft_putnbr_fd(int n, int fd);//testé-vérifier
char		*ft_strtrim(char const *s1, char const *set);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif