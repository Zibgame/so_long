/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:41:28 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/12 15:30:13 by zcadinot         ###   ########.fr       */
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
		perror("\n ERROR: Numbers of Argument incorect \n \n");
		return (1);
	}
	if (check_ber(argv[1]))
	{
		perror("\n ERROR: The extention is incorect \n \n");
		return (1);
	}
	else
	{
		fd = check_openable(argv[1]);
		if (fd == 0)
			return (0);
	}
	perror("\n SUCCES : Number of argument good \n \n");
	return (0);
}
