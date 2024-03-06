/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:49:44 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/21 22:43:10 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	wordcount(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	wordlen(const char *s, char del, int start)
{
	int	len;

	len = 0;
	while (s[start + len] && s[start + len] != del)
	{
		len++;
	}
	return (len);
}

static char	**free_split(char **arr, int word_index)
{
	while (word_index--)
	{
		free(arr[word_index]);
	}
	free(arr);
	return (NULL);
}

static char	*allocate_word(char const *s, char c, int *i)
{
	char	*word;
	int		word_len;

	word_len = wordlen((char *)s, c, *i);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*i], word_len + 1);
	*i += word_len;
	return (word);
}

/*
-Splits single string into multiple stings based on given delimeter
-Returns array of null terminated strings
*/
char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		word_index;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	word_index = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			arr[word_index] = allocate_word(s, c, &i);
			if (!arr[word_index])
				return (free_split(arr, word_index));
			word_index++;
		}
		else
			i++;
	}
	arr[word_index] = NULL;
	return (arr);
}
