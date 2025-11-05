/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:41:06 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/19 01:34:38 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	is_digit;

	is_digit = 1;
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (is_digit);
}

// int main(void)
// {
//     printf("%d\n", ft_isdigit('3'));
//     printf("%d\n", ft_isdigit('a'));
//     return (0);
// }
