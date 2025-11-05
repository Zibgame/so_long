/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:04:22 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/29 12:17:45 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned int	a;
	unsigned int	b;
	void			*ptr;

	a = 255;
	b = 3735928559;
	ptr = &a;
	ft_printf("%d ->", printf("%%\t%c\t%s\t%p\t%p\t%d\n%i\t%u\t%x\t%X\n\n", 'a', "aaa", &a, ptr, 0, -42, -1, 16, 16));
	ft_printf("%d ->", ft_printf("%%\t%c\t%s\t%p\t%p\t%d\n%i\t%u\t%x\t%X\n\n", 'a', "aaa", &a, ptr, 0, -42, -1, 16, 16));
	return (0);
}
