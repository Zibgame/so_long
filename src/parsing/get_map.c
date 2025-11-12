/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 15:33:29 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *path)
{
	ssize_t	bytes_read;
	char	buffer[1024 + 1];
	char	*content = NULL;
	char	*tmp;
	char	**map = NULL;
	int	fd;

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
		if (!tmp)
			return (NULL);
		content = tmp;
	}
	close(fd);
	if (!*content)
		return (free(content), NULL);
	map = ft_split(content, '\n');
	free(content);
	if (!map)
		return (NULL);
	return (map);
}
