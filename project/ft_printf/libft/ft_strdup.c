/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:55:36 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/26 18:09:24 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	ptr = malloc(sizeof(char) * i + 1);
	if (ptr == NULL)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
