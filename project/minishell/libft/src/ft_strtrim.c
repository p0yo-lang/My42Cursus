/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:54:21 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/28 03:12:16 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(int c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		left;
	int		right;
	int		i;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	while (s1[left] && search(s1[left], set))
		left++;
	right = ft_strlen((char *)s1);
	while (right > left && search(s1[right - 1], set))
		right--;
	str = malloc(sizeof(*s1) * right - left + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (left < right)
	{
		str[i] = s1[left];
		i++;
		left++;
	}
	str[i] = '\0';
	return (str);
}
