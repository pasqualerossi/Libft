/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:59:10 by prossi            #+#    #+#             */
/*   Updated: 2021/09/15 12:47:07 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		p;

	if (str == NULL)
		return (NULL);
	i = 0;
	p = 0;
	j = ft_word_count((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_alloc(((char *)str), c, &p);
		if (strs[i] == NULL)
		{
			ft_freeup(strs[i]);
		}
		i++;
	}
	return (strs);
}

static void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

static int	ft_word_count(char *str, char c)
{
	int	i;
	int	letter;

	i = 0;
	letter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			letter++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (letter);
		}
		i++;
	}
	return (letter);
}

static void	ft_strcpy(char *letter, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + 1] != c && str[j + i] != '\0')
	{
		letter[i] = str[j + i];
		i++;
	}
	letter[i] = '\0';
}

static char	*ft_alloc(char *str, char c, int *k)
{
	char	*letter;
	int		i;

	j = *k;
	letter = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			letter = (char *)malloc(sizeof(char) * (*k + 1));
			if (letter == NULL)
				return (NULL);
			return (0);
		}
		*k += 1;
	}
	ft_strcpy(letter, str, c, j);
	return (letter);
}
