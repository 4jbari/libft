/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:49:22 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:04:11 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	word;

	word = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && word == 1)
		{
			count++;
			word = 0;
		}
		else if (s[i] == c)
			word = 1;
		i++;
	}
	return (count);
}

static size_t	sslen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	ft_free(char **s, size_t j)
{
	while (j > 0)
	{
		free(s[--j]);
	}
	free(s);
}

static char	**split1(char const *s, char c, char **r)
{
	size_t	i;
	size_t	j;
	size_t	ssl;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			ssl = sslen(&s[i], c);
			r[j] = ft_substr(&s[i], 0, ssl);
			if (!r[j])
			{
				ft_free(r, j);
				return (0);
			}
			j++;
			i = i + ssl;
		}
	}
	r[j] = 0;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;

	if (s == 0)
		return (0);
	r = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (r == 0)
		return (0);
	return (split1(s, c, r));
}
