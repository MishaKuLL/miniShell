/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 21:49:00 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little, \
								size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_realloc(char *str, int len);
char				**ft_double_realloc(char **str, int len, char *line);
char				**ft_strtok(char *s, char *delim);
void				free_arr(char **arr);
int					skip_spaces(char *line);

#endif
