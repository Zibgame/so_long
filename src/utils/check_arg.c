/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:41:28 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/04 23:47:49 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_arg(int argc, char *argv[])
{
	if (argc >= 1)
	{
		perror("to much arguments");
		return(1);
	}
	perror("Check Arg Good");
	return(0);
}
