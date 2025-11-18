/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:41:28 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/18 15:15:43 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

int	check_arg(int argc, char *argv[])
{
	int	fd;

	if (argc > 2 || argc < 2)
	{
		perror("\n ERROR: The extention is incorect \n \n");
		return (1);
	}
	if (check_ber(argv[1]))
	{
		return (1);
	}
	else
	{
		fd = check_openable(argv[1]);
		if (fd < 0)
			return (1);
		close(fd);
	}
	return (0);
}
