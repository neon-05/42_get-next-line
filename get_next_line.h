/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:38:45 by ylabussi          #+#    #+#             */
/*   Updated: 2024/10/28 17:29:47 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10000000
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*_move_line_back(char **line, char *nl);
void	_replace_ptr(char **dst, void *src);

char	*ft_strchr(char *str, int search_str);
char	*ft_strldup(const char *s, size_t l);
size_t	ft_strlen(const char *s);
char	*ft_strljoin(char const *s1, char const *s2, size_t l);
int		ft_strlcat(char *dst, const char *src, size_t size);

#endif