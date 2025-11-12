/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 08:01:24 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *path)
{
	int		fd;
	char	buffer[1024 + 1];
	char	*content;
	char	*tmp;
	ssize_t	bytes_read;
	char	**map;

	fd = check_openable(path);
	if (fd <= 0)
		return (NULL);
	content = ft_strdup("");
	if (!content)
		return (NULL);
	while ((bytes_read = read(fd, buffer, 1024)) > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(content, buffer);
		free(content);
		content = tmp;
	}
	close(fd);
	if (!content || content[0] == '\0')
	{
		free(content);
		return (NULL);
	}
	map = ft_split(content, '\n');
	free(content);
	return (map);
}

