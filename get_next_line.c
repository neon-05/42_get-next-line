/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:40:02 by ylabussi          #+#    #+#             */
/*   Updated: 2024/10/28 17:09:22 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*fds[1024];
	char		*buffer;
	char		*nl;
	int			cc;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	cc = 1;
	while (!ft_strchr(fds[fd], '\n') && cc > 0)
	{
		cc = read(fd, buffer, BUFFER_SIZE);
		if (fds[fd])
			_replace_ptr(fds + fd,
				ft_strljoin(fds[fd], buffer, ft_strlen(fds[fd]) + cc + 1));
		else if (cc > 0)
			fds[fd] = ft_strldup(buffer, cc + 1);
	}
	nl = ft_strchr(fds[fd], '\n');
	if (!nl)
		nl = fds[fd] + ft_strlen(fds[fd]);
	free(buffer);
	return (_move_line_back(fds + fd, nl + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start > ft_strlen(s))
		start = ft_strlen(s);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub[0] = '\0';
	ft_strlcat(sub, &(s[start]), len + 1);
	return (sub);
}

char	*_move_line_back(char **line, char *nl)
{
	char	*final;
	char	*old;

	if (!*line)
		return (NULL);
	final = ft_substr(*line, 0, nl - *line);
	old = *line;
	if (*(nl - 1))
		*line = ft_strldup(nl, ft_strlen(nl) + 1);
	else
		*line = NULL;
	free(old);
	return (final);
}

void	_replace_ptr(char **dst, void *src)
{
	void	*tmp;

	tmp = *dst;
	*dst = src;
	free(tmp);
}
