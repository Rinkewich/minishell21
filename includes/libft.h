/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:45 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/06 19:53:10 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_inset(char c, char const *set);
int		ft_isdigit(int c);
size_t	ft_strlen( const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tolower(int c);
char	*ft_strtolower(const char *str);
int		ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(const char	*s, int fd);
char	*ft_strrchr(const char	*s, int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strndup(const char *str, int n);
int		ft_chrpos(char *str, char c);
char	**ft_split(char const *s, char c);
int		ft_arrlen(char **array);
char	**ft_arrnew(int len);
char	*ft_strdup(const char *s1);
char	*ft_strnew(int len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_str_addletter(char *old_word, char letter);
char	**ft_arr_addback(char **old_array, char *word);
size_t	ft_nbrlen(long nbr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
#endif
