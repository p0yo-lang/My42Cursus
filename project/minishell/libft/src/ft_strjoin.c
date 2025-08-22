/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:34:51 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/28 16:19:52 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strconc(char *str, char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = malloc(sizeof(*s1) * (s1_len + s2_len) + 1);
	if (!str)
		return (NULL);
	str = ft_strconc(str, s1, s2);
	return (str);
}
