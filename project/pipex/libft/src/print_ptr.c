/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:21:31 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/01/07 18:08:33 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr_hexa(va_list arg)
{
	void	*ptr;
	char	str[20];
	int		printed;

	ptr = va_arg(arg, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	printed = 2;
	ft_putstr_fd("0x", 1);
	convert_nbr_to_hex((unsigned long)ptr, str);
	ft_putstr_fd(str, 1);
	printed += ft_strlen(str);
	return (printed);
}
