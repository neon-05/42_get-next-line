/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:11:59 by ylabussi          #+#    #+#             */
/*   Updated: 2024/10/28 17:00:48 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strchr(char *str, int search_str)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return (NULL);
	ptr = NULL;
	i = 0;
	while (str[i] && str[i] != search_str)
		i++;
	if (str[i] == search_str)
		ptr = &(str[i]);
	return (ptr);
}

char	*ft_strldup(const char *s, size_t l)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof (char) * l);
	if (!new)
		return (NULL);
	i = 0;
	new[l - 1] = '\0';
	while (i < l - 1)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strljoin(char const *s1, char const *s2, size_t len)
{
	char	*new;

	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	*new = '\0';
	ft_strlcat(new, s1, len);
	ft_strlcat(new, s2, len);
	return (new);
}

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	offset;
	size_t	rval;

	rval = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (dst[i] != '\0')
		return (size + ft_strlen(src));
	offset = i;
	i = 0;
	while (src[i] && i + offset + 1 < size)
	{
		dst[i + offset] = src[i];
		i++;
	}
	dst[i + offset] = '\0';
	return (rval);
}
