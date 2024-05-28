/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:44:06 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/07 13:51:04 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **word)
{
	int	i;

	i = 0;
	while (word[i] != NULL)
	{
		free(word[i]);
		i++;
	}
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

static int	ft_wordlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*ft_fill_words(char const *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str, c);
	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (ft_free(&word), NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
		{
			array[j] = ft_fill_words(&s[i], c);
			if (array[j] == NULL)
				free(array);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	array[ft_wordcount(s, c)] = NULL;
	return (array);
}

// int	main(void)
// {
// 	int		i;
// 	char	**array;
// 	char	str[] = "\t\t\t\t\thello!\t\t\t\t\t\t\t";
// 	char	c;

// 	i = 0;
// 	c = '\t';
// 	array = ft_split(str, c);
// 	while (i < 2)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// 	return (0);
// }
