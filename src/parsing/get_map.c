/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 16:06:11 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file_content(int fd)
{
	ssize_t	bytes_read;
	char	buffer[1024 + 1];
	char	*content;
	char	*tmp;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 1024);
		if (bytes_read < 0)
		{
			free(content);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(content, buffer);
		if (!tmp)
		{
			free(content);
			return (NULL);
		}
		free(content);
		content = tmp;
	}
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
	content = read_file_content(fd);
	close(fd);
	if (!content || !*content)
		return (free(content), NULL);
	map = ft_split(content, '\n');
	free(content);
	return (map);
}
