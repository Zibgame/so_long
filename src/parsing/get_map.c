/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 17:03:53 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_content(int fd)
{
	char	buffer[1025];
	char	*content;
	char	*tmp;
	ssize_t	bytes;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	while ((bytes = read(fd, buffer, 1024)) > 0)
	{
		buffer[bytes] = '\0';
		tmp = ft_strjoin(content, buffer);
		if (!tmp)
			return (free(content), NULL);
		free(content);
		content = tmp;
	}
	if (!*content)
		return (free(content), NULL);
	return (content);
}

char	**get_map(char *path)
{
	int		fd;
	char	*content;
	char	**map;

	fd = check_openable(path);
	if (fd <= 0)
		return (NULL);
	content = read_content(fd);
	close(fd);
	if (!content)
		return (NULL);
	map = ft_split(content, '\n');
	free(content);
	return (map);
}
