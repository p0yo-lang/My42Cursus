/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:53:53 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/02/12 11:57:36 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*value;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	value = malloc((sizeof(char)) * (len + 1));
	if (!value)
		return (NULL);
	i = 0;
	while (i < len)
	{
		value[i] = s[start + i];
		i++;
	}
	value[i] = 0;
	return (value);
}

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
