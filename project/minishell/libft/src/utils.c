/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:07:00 by marslink          #+#    #+#             */
/*   Updated: 2025/09/05 21:16:33 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_format_specifier_valid(char format_specifier)
{
	char	*set;

	set = "cspdiuxX%";
	if (ft_memchr(set, format_specifier, 10) != NULL)
		return (1);
	return (0);
}
