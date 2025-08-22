/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:29:00 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/26 18:27:17 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*sdest;
	char	*ssrc;

	i = 0;
	ssrc = (char *)src;
	sdest = (char *)dest;
	if (sdest == NULL && ssrc == NULL)
	{
		return (NULL);
	}
	if (sdest > ssrc)
	{
		while (n-- > 0)
			sdest[n] = ssrc[n];
	}
	else
	{
		while (i < (int)n)
		{
			sdest[i] = ssrc[i];
			i++;
		}
	}
	return (sdest);
}
