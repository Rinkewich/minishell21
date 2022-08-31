/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:45 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/14 15:21:53 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_inset(char c, char const *set);
int		ft_isdigit(int c);
size_t	ft_strlen(const char	*s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
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
char	*ft_strndup(const char *str, int n);
int		ft_chrpos(char *str, char c);
char	**ft_split(char const *s, char c);

#endif
