/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:40 by marslink          #+#    #+#             */
/*   Updated: 2025/01/07 19:34:49 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_not_valid(const char *format)
{
	int	i;

	i = 0;
	ft_putchar_fd('%', 1);
	while (ft_isspace(format[i]))
	{
		ft_putchar_fd(format[i], 1);
		i++;
	}
	ft_putchar_fd(format[i], 1);
	return (i + 1);
}

static int	print_arg(const char *format, va_list arg)
{
	int	printed;
	int	i;

	i = 1;
	printed = 0;
	while (ft_isspace(format[i]))
		i++;
	if (is_format_specifier_valid(format[i]))
	{
		if (format[i] == 's')
			printed = print_str(arg);
		if (format[i] == 'c' || format[i] == '%')
			printed = print_char(arg, format[i]);
		if (format[i] == 'p')
			printed = print_ptr_hexa(arg);
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
			printed = print_nbr(arg, format[i]);
		if (format[i] == 'x' || format[i] == 'X')
			printed = print_hex(arg, format[i]);
	}
	else
		printed = print_not_valid(format);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			printed += print_arg(format, args);
			while (ft_isspace(*format))
				format++;
			format += 2;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
