/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:40:02 by ylabussi          #+#    #+#             */
/*   Updated: 2024/10/29 15:36:18 by ylabussi         ###   ########.fr       */
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

	if (!(0 <= fd && fd < 1024))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (_read_until_nl(fds, fd, buffer))
		return (NULL);
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

	if (!*line)
		return (NULL);
	if (!**line)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	final = ft_substr(*line, 0, nl - *line);
	if (*(nl - 1))
		_replace_ptr(line, ft_strldup(nl, ft_strlen(nl) + 1));
	else
		_replace_ptr(line, NULL);
	return (final);
}

void	_replace_ptr(char **dst, void *src)
{
	void	*tmp;

	tmp = *dst;
	*dst = src;
	free(tmp);
}

int	_read_until_nl(char **fds, int fd, char *buffer)
{
	int	cc;

	cc = 1;
	while (!ft_strchr(fds[fd], '\n') && cc > 0)
	{
		cc = read(fd, buffer, BUFFER_SIZE);
		if (cc < 0)
		{
			free(fds[fd]);
			free(buffer);
			fds[fd] = NULL;
			return (1);
		}
		if (fds[fd])
			_replace_ptr(fds + fd,
				ft_strljoin(fds[fd], buffer, ft_strlen(fds[fd]) + cc + 1));
		else if (cc != 0)
			fds[fd] = ft_strldup(buffer, cc + 1);
	}
	return (0);
}
