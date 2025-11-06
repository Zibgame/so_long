/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:13:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 16:17:49 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **get_map(char *path)
{
	int		fd;
	char	*line;
	char	*content;
	char	*tmp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("\n ERROR: Failed to open map file \n \n");
		return (NULL);
	}
	content = ft_strdup("");
	if (!content)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		tmp = ft_strjoin(content, line);
		free(content);
		free(line);
		content = tmp;
	}
	close(fd);
	map = ft_split(content, '\n');
	free(content);
	return (map);
}
