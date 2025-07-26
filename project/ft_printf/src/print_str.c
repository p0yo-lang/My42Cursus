/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:35 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/02/18 17:13:30 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list arg)
{
	int		printed;
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	printed = 0;
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		printed++;
		str++;
	}
	return (printed);
}
