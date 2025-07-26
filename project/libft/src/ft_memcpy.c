/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:17:24 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/26 18:05:04 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*sdest;
	char	*ssrc;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	ssrc = (char *)src;
	sdest = (char *)dest;
	while (i < (int)n)
	{
		sdest[i] = ssrc[i];
		i++;
	}
	return (sdest);
}
