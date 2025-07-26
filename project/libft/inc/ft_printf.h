/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:11:52 by marslink          #+#    #+#             */
/*   Updated: 2025/01/07 22:05:28 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_isspace(int c);
int		is_format_specifier_valid(char format_specifier);
int		print_str(va_list arg);
int		print_char(va_list arg, char format_specifier);
int		print_ptr_hexa(va_list arg);
int		print_nbr(va_list arg, char format_specifier);
int		print_hex(va_list arg, char format_specifier);
void	convert_nbr_to_hex(unsigned long nbr, char *str);

#endif