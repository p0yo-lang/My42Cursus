/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:38 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/01/07 19:43:10 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	get_digits_unbr(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	print_unbr(unsigned int n)
{
	int		digits;
	char	str[11];
	int		i;

	digits = get_digits_unbr(n);
	i = digits - 1;
	str[digits] = '\0';
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (digits);
}

int	print_nbr(va_list arg, char format_specifier)
{
	int				nbr;
	unsigned int	unbr;

	if (format_specifier == 'd' || format_specifier == 'i')
	{
		nbr = va_arg(arg, int);
		ft_putnbr_fd(nbr, 1);
		if (nbr >= 0)
			return (get_digits(nbr));
		return (get_digits(nbr) + 1);
	}
	unbr = va_arg(arg, unsigned int);
	return (print_unbr(unbr));
}
