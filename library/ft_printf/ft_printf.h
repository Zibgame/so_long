/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:34:50 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/05 21:08:16 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_printf(const char *s, ...);
int		parser(const char *str, va_list args);
int		ft_putarg_char(char type, va_list args);
int		ft_putarg_int(char type, va_list args);
int		ft_putarg_hex(char type, va_list args);
int		ft_putptr(void *ptr);
int		ft_putptr_recursive(unsigned long n);
int		ft_puthex_recursive(unsigned int n, char *base);
int		ft_putunbr_fd(unsigned int n, int fd);

#endif
