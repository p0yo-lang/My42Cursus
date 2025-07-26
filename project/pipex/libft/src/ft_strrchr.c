/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:54:13 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/26 18:09:31 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*value;

	value = NULL;
	while (*s)
	{
		if (*s == (char)c)
			value = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (value);
}
