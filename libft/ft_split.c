/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:07:55 by nide-mel          #+#    #+#             */
/*   Updated: 2021/08/07 18:09:33 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	strcounter(const char *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		while (str[i] == c && str[i] != '\0')
			i++;
		counter++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		start;

	new = malloc(sizeof(char *) * (strcounter(s, c) + 1));
	if (!s || !new)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		new[j] = ft_substr(s, start, i - start);
		j++;
	}
	new[j] = NULL;
	return (new);
}
