/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 01:33:04 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 05:39:24 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'))
		i++;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'))
			i++;
		if (s[i])
		{
			while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\v'))
				i++;
			size++;
		}
	}
	return (size);
}

char			**ft_strsplit_whitespace(char const *s)
{
	char	**tab;
	size_t	size;
	int		i;
	int		start;

	if (!s[0] || !s || !(tab = (char **)malloc(sizeof(char *)
					* (ft_words(s) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\v')
			i++;
		else
		{
			start = i;
			while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\v'))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}
