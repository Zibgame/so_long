/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:02:44 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/19 01:44:28 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_putnbr_fd(nb / 10, fd);
	len += write(fd, &(char){'0' + (nb % 10)}, 1);
	return (len);
}

// int main(void)
// {
//     ft_putnbr_fd(42, 1);
//     return (0);
// }
