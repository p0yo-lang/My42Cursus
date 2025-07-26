/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:18:41 by marslink          #+#    #+#             */
/*   Updated: 2025/01/07 19:39:39 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list arg, char format_specifier)
{
	char	c;

	if (format_specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	c = va_arg(arg, int);
	ft_putchar_fd((char)c, 1);
	return (1);
}
