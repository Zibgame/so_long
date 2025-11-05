/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:41:28 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 16:03:11 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <fcntl.h>
#include <unistd.h>

int check_arg(int argc, char *argv[])
{
	int fd;

	if (argc > 2 || argc < 2)
	{
		perror("\n ERROR: Numbers of Argument incorect \n \n");
		return(1);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);	
		if (fd < 0)
		{	
			perror("Error");
			close(fd);
			return (1);
		}
		close(fd);
	}
	perror("\n SUCCES : Number of argument good \n \n");
	return(0);
}
