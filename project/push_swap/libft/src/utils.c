/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:07:00 by marslink          #+#    #+#             */
/*   Updated: 2025/01/07 16:25:17 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_format_specifier_valid(char format_specifier)
{
	char	*set;

	set = "cspdiuxX%";
	if (ft_memchr(set, format_specifier, 10) != NULL)
		return (1);
	return (0);
}
