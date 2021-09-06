/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 09:35:31 by nide-mel          #+#    #+#             */
/*   Updated: 2021/08/07 18:04:43 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*str1;
	size_t	i;

	if (!str)
		return (NULL);
	str1 = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1));
	if (!str1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = 0;
	return (str1);
}
