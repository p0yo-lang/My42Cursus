/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:50 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/01/07 22:23:26 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_str(char *str)
{
	char	*start;
	char	*end;
	char	temp;

	start = str;
	end = str;
	while (*end)
		end++;
	end--;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void	convert_nbr_to_hex(unsigned long nbr, char *str)
{
	char			*hex_digits;
	int				i;

	hex_digits = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
		str[i++] = '0';
	else
	{
		while (nbr > 0)
		{
			str[i++] = hex_digits[nbr % 16];
			nbr /= 16;
		}
	}
	str[i] = '\0';
	reverse_str(str);
}

static void	str_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int	print_hex(va_list arg, char format_specifier)
{
	unsigned long	nbr;
	char			*str;
	int				printed;

	nbr = va_arg(arg, unsigned long);
	nbr = nbr & 0xFFFFFFFF;
	str = (char *)malloc(17 * sizeof(char));
	if (!str)
		return (0);
	convert_nbr_to_hex(nbr, str);
	if (format_specifier == 'X')
		str_toupper(str);
	ft_putstr_fd(str, 1);
	printed = ft_strlen((const char *)str);
	free(str);
	return (printed);
}
