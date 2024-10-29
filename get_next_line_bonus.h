/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:38:45 by ylabussi          #+#    #+#             */
/*   Updated: 2024/10/29 15:40:24 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*_move_line_back(char **line, char *nl);
void	_replace_ptr(char **dst, void *src);
int		_read_until_nl(char **fds, int fd, char *buffer);

char	*ft_strchr(char *str, int search_str);
char	*ft_strldup(const char *s, size_t l);
size_t	ft_strlen(const char *s);
char	*ft_strljoin(char const *s1, char const *s2, size_t l);
int		ft_strlcat(char *dst, const char *src, size_t size);

#endif