/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:58:41 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/28 12:59:29 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_extract_line(char *str)
{
	long	i;
	char	*res;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_read_fd(int fd, char *stash)
{
	ssize_t	byte_read;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(stash, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[byte_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*ft_clean_stash(char *stash)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new = malloc(ft_strlen(stash) - i);
	if (!new)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = NULL;
	stash[fd] = ft_read_fd(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}

/* #include <fcntl.h> */
/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	int		fd; */
/* 	char	*line; */
/* 	int		i; */

/* 	fd = open("test.txt", O_RDONLY); */
/* 	if (fd < 0) */
/* 	{ */
/* 		perror("Erreur lors de l'ouverture du fichie"); */
/* 		return (1); */
/* 	} */
/* 	i = 1; */
/* 	while ((line = get_next_line(fd)) != NULL) */
/* 	{ */
/* 		printf("Ligne %d : %s", i, line); */
/* 		free(line); */
/* 		i++; */
/* 	} */
/* 	get_next_line(-1); */
/* 	close(fd); */
/* 	return (0); */
/* } */
