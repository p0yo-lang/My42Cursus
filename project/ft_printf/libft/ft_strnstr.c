/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:29:34 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/28 02:49:00 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && !s)
		return (NULL);
	if (!*to_find)
		return ((char *)s);
	i = 0;
	while (s[i] && (size_t)i < len)
	{
		if (s[i] == to_find[0])
		{
			j = 0;
			while (s[i + j] == to_find[j] && i + j < len)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&s[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
