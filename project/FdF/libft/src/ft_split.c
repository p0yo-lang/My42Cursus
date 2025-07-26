/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:04:24 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/11/28 03:24:53 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static int	word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*allocate_word(char const *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = *s;
		i++;
		s++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_allocated_memory(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = allocate_word(s, word_length(s, c));
			if (!result[i])
			{
				free_allocated_memory(result, i);
				return (NULL);
			}
			s += word_length(s, c);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
